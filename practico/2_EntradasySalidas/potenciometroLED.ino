// Controlamos brillo de LED con un potenciometro

// Librerias

// Definicion de Pines
const int ledPin = 9; //Pin del LED. IMPORTANTE: El pin debe ser PWM para controlar el brillo
const int potPin = A0; //Pin del potenciometro

// Definicion de variables
int potValue = 0; //Variable para almacenar el valor del potenciometro

void setup() {
    pinMode(ledPin, OUTPUT); //Configura el pin del LED como salida
    pinMode(potPin, INPUT); //Configura el pin del potenciometro como entrada
    Serial.begin(9600); //Inicia la comunicacion serial a 9600 baudios
}

void loop() {
    potValue = analogRead(potPin); //Lee el valor del potenciometro (0-1023)
    int brillo = map(potValue, 0, 1023, 0, 255); //Mapea el valor del potenciometro a un rango de brillo (0-255)

    analogWrite(ledPin, brillo); //Controla el brillo del LED utilizando PWM

    // Imprime el valor del potenciometro y el brillo del LED en el monitor serial
    Serial.print("Valor del Potenciometro: ");
    Serial.print(potValue);
    Serial.print(" - Brillo del LED: ");
    Serial.println(brillo);

    delay(100); //Pequeña pausa para evitar saturar el monitor serial
}