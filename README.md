# 💻 Del Código al Mundo Real: Programá Hardware con Arduino

Material del workshop teórico-práctico de sistemas embebidos con Arduino, dictado por el **Programa de Educación en Ciencia y Tecnología (PECyT)**, dependiente de la **Secretaría de Extensión Universitaria** de la **Universidad Nacional de Córdoba (UNC)**.

La actividad está destinada a estudiantes de la UNC (especialmente de carreras vinculadas a la computación: Ingeniería en Computación, Tecnicatura en Sistemas Digitales, Ciencias de la Computación y afines) que quieran dar sus primeros pasos en el desarrollo de sistemas embebidos.

## 🗂️ Estructura del repositorio

```
workshop_arduino/
├── Del_Codigo_al_Mundo_Real_-_Manual_Teorico.pdf   # Manual teórico completo
└── practico/
    ├── 1_LEDS/      # Fundamentos de programación: setup/loop, LEDs, secuencias
    ├── 2_EntradasySalidas/      # Entradas y señales: lectura analógica con potenciómetro + PWM
    ├── 3_Motores/      # Codigo para trabajar con motores
    ├── 4_LCD/      # Visualización con LCD I2C (mensajes y cronómetro)
    └── 5_Sensores/      # Sensores: DHT11 (temperatura/humedad), HC-SR04 (ultrasónico), LDR (fotorresistor)
```

Cada carpeta de `practico/` contiene los sketches (`.ino`) que se completan en vivo durante el workshop. Algunos archivos incluyen comentarios `//TODO` para completar durante la clase; otros están completos y se usan para correr y analizar el funcionamiento.

## 🔧 Requisitos de software

- [Arduino IDE 2.x](https://www.arduino.cc/en/software)
- Librerías (instalar desde *Herramientas → Administrar Librerías*):
  - `LiquidCrystal_I2C` (Frank de Brabander, o compatible)
  - `DHT sensor library` (Adafruit) + `Adafruit Unified Sensor`


## 📖 Manual teórico

El manual teórico completo (electrónica básica, plataforma Arduino, programación, entradas/señales, LCD y sensores) está incluido en este repositorio.

## 📬 Contacto

Para dudas sobre los contenidos o futuras actividades del programa:

- **Correo electrónico:** educacionencyt@extension.unc.edu.ar
- **Instagram:** [@unc.extension](https://www.instagram.com/unc.extension)
- **Área:** Programa de Educación en Ciencia y Tecnología (PECyT) — Secretaría de Extensión, UNC

_miniServer es algo sorpresa...si dan los tiempos intentaremos hacerlo_