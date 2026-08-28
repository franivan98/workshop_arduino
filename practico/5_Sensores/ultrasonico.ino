// Prender y apagar un LED utilizando un sensor ultrasonico

// Librerias

// Definicion de Pines
const int TRIGGER_PIN = 9; // Pin de disparo del sensor ultrasonico
const int ECHO_PIN = 10; // Pin de eco del sensor ultrasonico
const int LED_PIN = 13; // Pin del LED

// Funciones

/**
 * Calcula la distancia utilizando el sensor ultrasonico
 * @return La distancia en centímetros
 */
float distancia_Ultrasonico(){
    // Enviar un pulso de disparo
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Medir el tiempo del eco
    long duration = pulseIn(ECHO_PIN, HIGH);

    // Calcular la distancia en centímetros
    float distance = (duration * 0.034) / 2;

    return distance;
}

void setup() {
    pinMode(TRIGGER_PIN, OUTPUT); // Configura el pin de disparo como salida
    pinMode(ECHO_PIN, INPUT); // Configura el pin de eco como entrada
    pinMode(LED_PIN, OUTPUT); // Configura el pin del LED como salida
}

void loop() {
    float distance = distancia_Ultrasonico(); // Calcula la distancia utilizando el sensor ultrasonico

    //TODO: Encender el LED si la distancia es menor a 10 cm, apagarlo en caso contrario
    
    delay(100); // Espera un poco antes de la siguiente medición
}