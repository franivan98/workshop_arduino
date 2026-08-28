// Cambiar secuencia de LEDs utilizando un botón

// Librerias

// Definicion de Pines
const int ledPins[] = {10, 11, 12, 13}; //Pines de los LEDs
const int buttonPin = 2; //Pin del botón

// Definicion de variables

// Funciones

void secuencia1(){
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], HIGH); //Enciende el LED
        delay(500); //Espera 500 ms
        digitalWrite(ledPins[i], LOW); //Apaga el LED
        delay(500); //Espera 500 ms
    }
}

void secuencia2(){
    for (int i = 3; i >= 0; i--) {
        digitalWrite(ledPins[i], HIGH); //Enciende el LED
        delay(500); //Espera 500 ms
        digitalWrite(ledPins[i], LOW); //Apaga el LED
        delay(500); //Espera 500 ms
    }
}

void setup(){
    // Configurar los pines de los LEDs como salida
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    // Configurar el pin del botón como entrada
    pinMode(buttonPin, INPUT_PULLUP); //Usamos INPUT_PULLUP para evitar ruido en la lectura del botón
}

void loop(){
    // hace la secuencia1 si el botón está presionado, de lo contrario hace la secuencia2
    if (digitalRead(buttonPin) == HIGH) {
        secuencia1();
    } else {
        secuencia2();
    }

    //TODO: Modificar el codigo para cambiar la secuencia de los LEDs cada vez que se presione el botón
}