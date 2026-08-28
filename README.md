# 💻 Del Código al Mundo Real: Programá Hardware con Arduino

Material de cátedra del workshop teórico-práctico de sistemas embebidos con Arduino, dictado por el **Programa de Educación en Ciencia y Tecnología (PECyT)**, dependiente de la **Secretaría de Extensión Universitaria** de la **Universidad Nacional de Córdoba (UNC)**.

La actividad está destinada a estudiantes de la UNC (especialmente de carreras vinculadas a la computación: Ingeniería en Computación, Tecnicatura en Sistemas Digitales, Ciencias de la Computación y afines) que quieran dar sus primeros pasos en el desarrollo de sistemas embebidos.

## 📋 Sobre el workshop

- **Duración:** 4hs (16:00 a 20:00hs)
- **Modalidad:** teórico-práctica, con ejercicios guiados en cada módulo
- **Requisito previo:** conocimientos básicos de programación (no se requiere experiencia previa en electrónica)

## 👨‍💻 Equipo docente

- **Miqueas Peñalva** — Est. Ing. Electrónica (UNC), docente en robótica, programación e impresión 3D
- **Franco Mamani** — Est. avanzado Ing. en Computación (UNC), Encargado Técnico del Área Educativa-Tecnológica, PECyT

## 🗂️ Estructura del repositorio

```
workshop_arduino/
├── Del_Codigo_al_Mundo_Real_-_Manual_Teorico.pdf   # Manual teórico completo
└── practico/
    ├── Unidad_1/      # Fundamentos de programación: setup/loop, LEDs, secuencias
    ├── Unidad_2/      # Entradas y señales: lectura analógica con potenciómetro + PWM
    ├── Unidad_3/      # Visualización con LCD I2C (mensajes y cronómetro)
    └── Unidad_4/      # Sensores: DHT11 (temperatura/humedad), HC-SR04 (ultrasónico), LDR (fotorresistor)
```

Cada carpeta de `practico/` contiene los sketches (`.ino`) que se completan en vivo durante el workshop. Algunos archivos incluyen comentarios `//TODO` para completar durante la clase; otros están completos y se usan para correr y analizar el funcionamiento.

## 📚 Contenidos por unidad

| Unidad | Tema | Sketches |
|---|---|---|
| 1 | Fundamentos de programación (`setup()`, `loop()`, Serial, variables) | `holaMundo.ino`, `parpadeo_led.ino`, `secuenciaLeds.ino` |
| 2 | Entradas y señales analógicas, PWM, `map()` | `potenciometroLED.ino` |
| 3 | Pantalla LCD 16x2 con módulo I2C | `mensajesLCD.ino`, `LCD_Cronometro.ino` |
| 4 | Sensores (temperatura/humedad, distancia, luz) | `dht11.ino`, `ultrasonico.ino`, `fotoresistor.ino` |

## 🔧 Requisitos de software

- [Arduino IDE 2.x](https://www.arduino.cc/en/software)
- Librerías (instalar desde *Herramientas → Administrar Librerías*):
  - `LiquidCrystal_I2C` (Frank de Brabander, o compatible)
  - `DHT sensor library` (Adafruit) + `Adafruit Unified Sensor`

## 📦 Componentes utilizados

Arduino UNO (o compatible), protoboard, cables Dupont, LEDs + resistencias 220Ω, potenciómetro 10kΩ, módulo LCD 16x2 I2C, sensor DHT11, sensor ultrasónico HC-SR04, fotorresistor (LDR) + resistencia 10kΩ.

## 📖 Manual teórico

El manual teórico completo (electrónica básica, plataforma Arduino, programación, entradas/señales, LCD y sensores) está incluido en este repositorio.

## 📬 Contacto

Para dudas sobre los contenidos o futuras actividades del programa:

- **Correo electrónico:** educacionencyt@extension.unc.edu.ar
- **Instagram:** [@unc.extension](https://www.instagram.com/unc.extension)
- **Área:** Programa de Educación en Ciencia y Tecnología (PECyT) — Secretaría de Extensión, UNC