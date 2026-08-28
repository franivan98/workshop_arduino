import requests
import time
import random

URL = "http://localhost:8000/update"
GRUPOS = ["Robot-X", "Team-Alpha", "Sistemas-1"]

while True:
    for grupo in GRUPOS:
        payload = {
            "group_name": grupo,
            "data": {
                "temp": f"{random.uniform(20, 30):.1f}",
                "hum": f"{random.randint(40, 60)}%",
                "voltaje": f"{random.uniform(3.1, 5.0):.2f}V",
                "status": random.choice(["OK", "WAIT", "ALARM"])
            }
        }
        try:
            requests.post(URL, json=payload, timeout=1)
        except:
            pass
    time.sleep(1)