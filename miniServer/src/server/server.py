from fastapi import FastAPI
from fastapi.responses import HTMLResponse
from pydantic import BaseModel
from typing import Dict, List
import uvicorn
import time

app = FastAPI()

# Estructura para almacenar todo: { "GrupoA": {"data": {...}, "history": {...}, "last_seen": timestamp} }
db = {}
MAX_HISTORY = 20  # Puntos para el gráfico
TIMEOUT_OFFLINE = 10 # Segundos para considerar a un grupo "Desconectado"

class Telemetria(BaseModel):
    group_name: str
    data: Dict[str, str]

@app.post("/update")
async def update(tele: Telemetria):
    now = time.time()
    name = tele.group_name
    
    if name not in db:
        db[name] = {"history": {}, "last_seen": now}
    
    # Actualizar último dato y tiempo
    db[name]["data"] = tele.data
    db[name]["last_seen"] = now
    
    # Guardar en historial para los gráficos (solo números)
    for k, v in tele.data.items():
        try:
            val_float = float(v.replace("°C", "").replace("%", "").replace("V", ""))
            if k not in db[name]["history"]:
                db[name]["history"][k] = []
            db[name]["history"][k].append(val_float)
            # Mantener solo los últimos N puntos
            if len(db[name]["history"][k]) > MAX_HISTORY:
                db[name]["history"][k].pop(0)
        except ValueError:
            continue # Si no es número, no va al gráfico
            
    return {"status": "ok"}

@app.get("/api/data")
async def get_all():
    # Agregamos el cálculo de estado antes de enviar
    now = time.time()
    for name in db:
        db[name]["status"] = "Online" if (now - db[name]["last_seen"]) < TIMEOUT_OFFLINE else "Offline"
    return db

@app.get("/", response_class=HTMLResponse)
async def home():
    return """
    <!DOCTYPE html>
    <html>
    <head>
        <title>Workshop Control Center</title>
        <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
        <style>
            :root { --bg: #0f172a; --card: #1e293b; --text: #f8fafc; --accent: #38bdf8; }
            body { font-family: 'Inter', sans-serif; background: var(--bg); color: var(--text); margin: 0; }
            
            nav { 
                background: #020617; padding: 1rem; display: flex; gap: 20px; 
                position: sticky; top: 0; z-index: 1000; box-shadow: 0 4px 6px -1px rgba(0,0,0,0.3); 
            }
            nav button { background: none; border: none; color: var(--text); cursor: pointer; font-size: 1rem; padding: 5px 10px; }
            nav button.active { border-bottom: 2px solid var(--accent); color: var(--accent); }
            
            .content { padding: 20px; }
            
            /* CLAVE PARA EL ERROR: Usamos una clase de visualización que mande sobre el resto */
            .tab-content { display: none; } 
            .tab-content.active { display: block; }

            .grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(250px, 1fr)); gap: 20px; }
            
            .card { background: var(--card); padding: 20px; border-radius: 12px; border: 1px solid #334155; }
            .status-dot { height: 10px; width: 10px; border-radius: 50%; display: inline-block; margin-right: 5px; }
            .online { background: #22c55e; box-shadow: 0 0 8px #22c55e; }
            .offline { background: #ef4444; }
            
            .chart-container { background: var(--card); padding: 15px; border-radius: 12px; height: 320px; border: 1px solid #334155; }
            
            table { width: 100%; border-collapse: collapse; background: var(--card); border-radius: 12px; overflow: hidden; }
            th, td { padding: 15px; text-align: left; border-bottom: 1px solid #334155; }
            th { background: #0f172a; color: var(--accent); }
        </style>
    </head>
    <body>
        <nav>
            <strong style="color: var(--accent); margin-right: 20px;">WORKSHOP HUB</strong>
            <button onclick="showTab('cards')" id="btn-cards" class="active">Panel</button>
            <button onclick="showTab('charts')" id="btn-charts">Gráficos</button>
            <button onclick="showTab('status')" id="btn-status">Estados</button>
        </nav>

        <div class="content">
            <!-- Cada sección ahora es un tab-content -->
            <div id="view-cards" class="tab-content active">
                <div id="cards-container" class="grid"></div>
            </div>
            
            <div id="view-charts" class="tab-content">
                <div id="charts-grid" class="grid"></div>
            </div>
            
            <div id="view-status" class="tab-content">
                <table>
                    <thead>
                        <tr>
                            <th>Grupo</th>
                            <th>Estado</th>
                            <th>Última Conexión</th>
                            <th>Sensores Activos</th>
                        </tr>
                    </thead>
                    <tbody id="status-table-body"></tbody>
                </table>
            </div>
        </div>

        <script>
            let charts = {};

            function showTab(tabId) {
                // Ocultamos todos los contenidos y sacamos el active de los botones
                document.querySelectorAll('.tab-content').forEach(el => el.classList.remove('active'));
                document.querySelectorAll('nav button').forEach(el => el.classList.remove('active'));
                
                // Mostramos el seleccionado
                document.getElementById('view-' + tabId).classList.add('active');
                document.getElementById('btn-' + tabId).classList.add('active');
            }

            async function update() {
                try {
                    const res = await fetch('/api/data');
                    const db = await res.json();
                    
                    // 1. Actualizar Tarjetas (dentro de su contenedor grid)
                    const cardCont = document.getElementById('cards-container');
                    cardCont.innerHTML = Object.entries(db).map(([name, info]) => `
                        <div class="card">
                            <h3 style="margin-top:0; color: var(--accent)">${name}</h3>
                            ${Object.entries(info.data).map(([k, v]) => `
                                <div style="display:flex; justify-content:space-between; margin-bottom:5px">
                                    <span style="color:#94a3b8">${k}:</span>
                                    <span style="font-weight:bold">${v}</span>
                                </div>
                            `).join('')}
                        </div>
                    `).join('');

                    // 2. Actualizar Tabla de Estados
                    const tableBody = document.getElementById('status-table-body');
                    tableBody.innerHTML = Object.entries(db).map(([name, info]) => {
                        const timeStr = new Date(info.last_seen * 1000).toLocaleTimeString();
                        const statusClass = info.status.toLowerCase();
                        return `
                        <tr>
                            <td><strong>${name}</strong></td>
                            <td><span class="status-dot ${statusClass}"></span> ${info.status}</td>
                            <td>${timeStr}</td>
                            <td style="color:#94a3b8; font-size:0.9em">${Object.keys(info.data).join(', ')}</td>
                        </tr>`;
                    }).join('');

                    // 3. Actualizar Gráficos
                    const chartsGrid = document.getElementById('charts-grid');
                    for (const [name, info] of Object.entries(db)) {
                        if (Object.keys(info.history).length > 0) {
                            const canvasId = 'chart-' + name.replace(/[^a-z0-9]/gi, '-');
                            if (!document.getElementById(canvasId)) {
                                const div = document.createElement('div');
                                div.className = 'chart-container';
                                div.innerHTML = `<canvas id="${canvasId}"></canvas>`;
                                chartsGrid.appendChild(div);
                            }
                            renderChart(canvasId, name, info.history);
                        }
                    }
                } catch (e) { console.error("Error en update:", e); }
            }

            function renderChart(canvasId, groupName, history) {
                const ctx = document.getElementById(canvasId).getContext('2d');
                const datasets = Object.entries(history).map(([label, data], idx) => ({
                    label: label,
                    data: data,
                    borderColor: ['#38bdf8', '#818cf8', '#fb7185', '#a6e3a1'][idx % 4],
                    backgroundColor: ['#38bdf822', '#818cf822', '#fb718522', '#a6e3a122'][idx % 4],
                    fill: true,
                    tension: 0.4
                }));

                if (charts[canvasId]) {
                    charts[canvasId].data.labels = Array(datasets[0].data.length).fill('');
                    charts[canvasId].data.datasets = datasets;
                    charts[canvasId].update('none');
                } else {
                    charts[canvasId] = new Chart(ctx, {
                        type: 'line',
                        data: { labels: Array(datasets[0].data.length).fill(''), datasets },
                        options: { 
                            responsive: true, 
                            maintainAspectRatio: false,
                            animation: false,
                            plugins: { 
                                title: { display: true, text: 'Grupo: ' + groupName, color: '#f8fafc', font: {size: 16} },
                                legend: { labels: { color: '#94a3b8' } }
                            },
                            scales: { 
                                y: { grid: { color: '#334155' }, ticks: { color: '#94a3b8' } },
                                x: { grid: { display: false } }
                            }
                        }
                    });
                }
            }

            setInterval(update, 1000);
            update();
        </script>
    </body>
    </html>
    """
if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)