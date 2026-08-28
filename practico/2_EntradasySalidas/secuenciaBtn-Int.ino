// Ejercicio de secuencia de LEDs utilizando boton con interrupcion

// En ARDUINO UNO, los pines 2 y 3 son los que soportan interrupciones externas, por lo que el botón debe estar 
// conectado a uno de estos pines para que la interrupción funcione correctamente. En este caso, el botón está 
// conectado al pin 2.

//Librerias

//Definicion de Pines
const int ledPins[] = {10, 11, 12, 13}; //Pines de los LEDs
const int buttonPin = 2; //Pin del botón

//Definicion de variables
volatile int secuencia = 0; //Variable para almacenar la secuencia actual

//Funciones
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

void interrupcion(){
    if(secuencia == 1){
        secuencia = 2;
    } else {
        secuencia = 1;
    }
}

void setup(){
    // Configurar los pines de los LEDs como salida
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    // Configurar el pin del botón como entrada
    pinMode(buttonPin, INPUT_PULLUP); //Usamos INPUT_PULLUP para evitar ruido en la lectura del botón
    // Configurar la interrupción para el botón
    attachInterrupt(digitalPinToInterrupt(buttonPin), interrupcion, RISING);
}

void loop(){
    // hace la secuencia1 si secuencia es 1, de lo contrario hace la secuencia2
    if (secuencia == 1) {
        secuencia1();
    } else {
        secuencia2();
    }
}