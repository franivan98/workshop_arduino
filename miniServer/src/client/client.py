import serial
import serial.tools.list_ports
import requests
import time

# === CONFIGURACIÓN ===
SERVER_IP = "172.22.142.36"
PORT = 8000
URL = f"http://{SERVER_IP}:{PORT}/update"
BAUD_RATE = 9600

def seleccionar_puerto():
    while True:
        puertos = list(serial.tools.list_ports.comports())
        if not puertos:
            print("\n [X] No se detectaron puertos serie. ¿Está conectado el Arduino?")
            input("Presioná Enter para volver a escanear...")
            continue

        print("\n--- Puertos Disponibles ---")
        for i, p in enumerate(puertos):
            print(f"[{i}] {p.device} - {p.description}")
        
        try:
            opcion = input("\nSeleccioná el número del puerto: ")
            idx = int(opcion)
            if 0 <= idx < len(puertos):
                return puertos[idx].device
            else:
                print(" [?] Número inválido.")
        except ValueError:
            print(" [?] Ingresá un número.")

def parsear_linea(linea):
    datos = {}
    for par in linea.split(','):
        if ':' in par:
            k, v = par.split(':', 1)
            datos[k.strip()] = v.strip()
    return datos

def main():
    try:
        print("==========================================")
        print("   CLIENTE DE TELEMETRÍA (MODO DEBUG)    ")
        print("==========================================\n")

        grupo = input(">> Nombre del Grupo: ").strip()
        if not grupo: grupo = "SinNombre"

        puerto_elegido = seleccionar_puerto()
        
        print(f"[*] Intentando abrir {puerto_elegido}...")
        ser = serial.Serial(puerto_elegido, BAUD_RATE, timeout=1)
        ser.reset_input_buffer()
        
        print(f"\n[+] CONECTADO EXITOSAMENTE.")
        print(f"[+] Enviando a: {URL}")
        print("[*] Presioná Ctrl+C para salir.\n")

        while True:
            if ser.in_waiting > 0:
                linea = ser.readline().decode('utf-8', errors='ignore').strip()
                if linea:
                    datos = parsear_linea(linea)
                    
                    if datos:
                        payload = {"group_name": grupo, "data": datos}
                        try:
                            requests.post(URL, json=payload, timeout=0.5)
                            print(f" [OK] {datos}")
                        except:
                            print(" [!] Error de red: El servidor no responde.")
                    else:
                        print(f" [?] Línea no parseable: {linea}")

            time.sleep(0.01)

    except serial.SerialException as e:
        print(f"\n[ERROR DE PUERTO] {e}")
        print("CAUSA: El puerto está siendo usado por el Arduino IDE o está mal conectado.")
    except KeyboardInterrupt:
        print("\n[*] Saliendo...")
    except Exception as e:
        print(f"\n[ERROR CRÍTICO] {e}")
    finally:
        print("\n" + "="*40)
        input("EL PROGRAMA TERMINÓ. Presioná ENTER para cerrar esta ventana...")
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == "__main__":
    main()