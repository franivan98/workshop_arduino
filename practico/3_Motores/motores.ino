// Control de Dos Motores (Autito) con Driver L298N (Sin velocidad)

// Librerias

// Definicion de Pines
// Motor A (Ejemplo: Rueda Derecha)
const int IN1 = 8;
const int IN2 = 7;
// Motor B (Ejemplo: Rueda Izquierda)
const int IN3 = 5;
const int IN4 = 4;

// Definicion de variables

/**
    * El setup se ejecuta una sola vez al iniciar el programa
     y se utiliza para configurar los pines, iniciar la comunicacion serial, etc.
 */
void setup(){
    Serial.begin(9600); // Inicia la comunicacion serial a 9600 baudios
    
    // Configurar todos los pines de direccion como salidas
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

/**
    * El loop se ejecuta continuamente despues de setup.
     El autito avanzará, se detendrá, retrocederá y se volverá a detener.
 */
void loop(){
    // TODO: Modularizar el código para que cada movimiento (avanzar, detener, retroceder) sea una función separada.
    // ej: avanzar(), detener(), retroceder()
    // 1. Avanzar (Ambos motores hacia ADELANTE)
    Serial.println("Autito AVANZANDO");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(2000); // Espera 2 segundos

    // 2. Detener (Ambos motores DETENIDOS)
    Serial.println("Autito DETENIDO");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(1000); // Espera 1 segundo

    // 3. Retroceder (Ambos motores hacia ATRAS)
    Serial.println("Autito RETROCEDIENDO");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(2000); // Espera 2 segundos

    // 4. Detener (Ambos motores DETENIDOS)
    Serial.println("Autito DETENIDO");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(1000); // Espera 1 segundo
}