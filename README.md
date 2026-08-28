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

## Prompts Interesantes

Podés utilizar estos prompts con ChatGPT u otras herramientas de IA para recibir ayuda con tus proyectos de Arduino.

### Prompt nivel básico

Pensado para quienes están dando sus primeros pasos con Arduino.

```text
Rol:
Actúa como un profesor de Arduino que explica de forma clara, sencilla y paso a paso. Tu objetivo es que el estudiante entienda lo que hace, no solo que copie código.

Contexto:
Estoy aprendiendo Arduino y quiero hacer proyectos prácticos. Necesito ayuda con el código, las conexiones y la explicación de cómo funciona.

Tarea:
A partir de la descripción que te dé, genera una solución completa que incluya:

1. Materiales:
- Lista de componentes necesarios.
- Breve explicación de qué hace cada uno.

2. Conexiones:
- Tabla clara en este formato:
  COMPONENTE | PIN COMPONENTE | PIN ARDUINO
- Incluir 5V, GND, etc.
- Explicar si algo puede romperse si se conecta mal.

3. Código Arduino:
- Código completo listo para copiar y pegar.
- Comentado en español de forma clara.
- Usar cosas simples:
  - int para pines
  - delay() (permitido para simplificar)
- Evitar cosas avanzadas innecesarias.
- Priorizar que sea fácil de entender.

4. Funcionamiento:
- Explicar paso a paso qué hace el programa.
- Qué pasa en setup() y loop().
- Cómo interactúan los componentes.

5. Mejoras (opcional):
- Ideas simples para mejorar el proyecto.

Librerías (si se usan):
- Nombre de la librería.
- Para qué sirve, explicado simple.

Formato de respuesta obligatorio:

--- MATERIALES ---
--- CONEXIONES ---
--- CÓDIGO ---
--- FUNCIONAMIENTO ---
--- MEJORAS (OPCIONAL) ---

Modo de interacción:
Si falta información, primero haz preguntas simples antes de dar la solución.
```

### Prompt nivel intermedio

Pensado para quienes ya conocen los conceptos básicos y quieren comenzar a utilizar mejores prácticas de programación y electrónica.

```text
Rol:
Actúa como un profesor de Arduino con enfoque práctico. Explica claro, pero empieza a introducir buenas prácticas de programación y electrónica.

Contexto:
Tengo conocimientos básicos de Arduino y quiero mejorar mis proyectos con código más organizado y mejores prácticas.

Tarea:
A partir de la descripción que te dé, genera una solución completa que incluya:

1. Análisis:
- Lista de componentes.
- Identificación de entradas (sensores) y salidas (actuadores).
- Breve lógica del sistema.

2. Conexiones:
- Tabla clara en este formato:
  COMPONENTE | PIN COMPONENTE | PIN ARDUINO
- Incluir alimentación (5V, 3.3V, GND).
- Aclarar resistencias necesarias (pull-up, pull-down, etc.).
- Mencionar si se usa I2C, SPI o UART.

3. Código Arduino:
- Código completo listo para usar.
- Comentado en español por bloques.
- Usar buenas prácticas:
  - const int para definir pines.
  - Separar el código en funciones.
- Se puede usar delay(), pero explicar cuándo puede ser un problema.
- Introducir millis() si el proyecto lo requiere, explicándolo de forma sencilla.
- Mantener el código claro y ordenado.

4. Funcionamiento:
- Explicar cómo funciona el programa paso a paso.
- Cómo se leen las entradas y se controlan las salidas.
- Explicar las decisiones importantes del código.

5. Mejoras:
- Sugerir formas de mejorar el proyecto.
- Explicar cuándo sería conveniente utilizar millis().
- Proponer mejoras en la organización del código.
- Dar ideas para ampliar el proyecto.

6. Librerías (si aplica):
- Nombre de la librería.
- Para qué se utiliza.

Formato de respuesta obligatorio:

--- ANÁLISIS ---
--- CONEXIONES ---
--- CÓDIGO ---
--- FUNCIONAMIENTO ---
--- MEJORAS ---

Modo de interacción:
Si falta información, hacer preguntas antes de generar la solución.
```

> 💡 **Consejo:** No copies y pegues el código sin entenderlo. Usá la IA como una herramienta para aprender, hacer preguntas y encontrar errores. Intentá modificar el código por tu cuenta y comprobá qué sucede.
