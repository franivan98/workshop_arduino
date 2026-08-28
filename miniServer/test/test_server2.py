import requests
import time
import random

URL = "http://localhost:8000/update"

def enviar(nombre, datos):
    try:
        payload = {"group_name": nombre, "data": datos}
        r = requests.post(URL, json=payload, timeout=1)
        return r.status_code
    except:
        return "Error"

print("🚀 Iniciando Simulación de Workshop Profesional...")
print("[-] Tip: Mirá la pestaña 'Estados' para ver quién se cae.\n")

contador = 0
while True:
    contador += 1
    
    # 1. GRUPO ESTABLE (Siempre Online)
    enviar("Grupo-Estable", {
        "temp": f"{random.uniform(24, 26):.1f}",
        "cpu": f"{random.randint(10, 30)}%"
    })

    # 2. GRUPO INTERMITENTE (Aparece y desaparece)
    # Solo envía datos cada 10 iteraciones
    if contador % 10 == 0:
        print("[!] Grupo-Intermitente acaba de reconectar...")
        enviar("Grupo-Intermitente", {"vbat": "3.7V"})
    
    # 3. GRUPO SENSORES (Muchos datos para el gráfico)
    enviar("Laboratorio-A", {
        "humedad": f"{random.uniform(40, 70):.1f}",
        "luz": f"{random.randint(200, 800)}",
        "presion": f"{random.uniform(1010, 1020):.1f}"
    })

    # 4. GRUPO NUEVO (Aparece de la nada a mitad del test)
    if contador == 5:
        print("[+] Un nuevo grupo se ha unido al workshop.")
        enviar("Grupo-Nuevo", {"status": "Iniciando"})

    print(f"[*] Ciclo {contador} completado. Datos enviados.")
    
    # Esperamos 2 segundos entre ciclos
    # El 'Grupo-Intermitente' se pondrá Offline a los 10 segundos 
    # (según el TIMEOUT_OFFLINE que pusimos en el server).
    time.sleep(2)