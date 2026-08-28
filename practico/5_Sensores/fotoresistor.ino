// Prender y apagar un LED utilizando un fotoresistor

// Librerias

// Definicion de Pines
const int fotoresistorPin = A0; // Pin del fotoresistor
const int LEDPin = 13; // Pin del LED

void setup() {
    pinMode(LEDPin, OUTPUT); // Configura el pin del LED como salida
}

void loop(){
    int valorFotoresistor = analogRead(fotoresistorPin); // Lee el valor del fotoresistor.
    // El valor del fotoresistor puede variar entre 0 (completamente oscuro) y 1023 (completamente iluminado).

    //TODO: Encender el LED si el valor del fotoresistor es menor a 500, apagarlo en caso contrario

    delay(100); // Espera un poco antes de la siguiente lectura
}