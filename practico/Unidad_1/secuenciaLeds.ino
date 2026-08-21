// Secuencias con 4 LEDs

//Librerias

//Definicion de Pines
const int ledPin1 = 11;
const int ledPin2 = 12;
const int ledPin3 = 13;

// En lugar de definir cada pin por separado, se puede utilizar un array para almacenar los pines de los LEDs
//const int ledPins[] = {10, 11, 12, 13}; //Pines de los LEDs

//Definicion de variables

/**
    * El setup se ejecuta una sola vez al iniciar el programa
     y se utiliza para configurar los pines, iniciar la comunicacion serial, etc.
 */
void setup(){
    // Configura los pines de los LEDs como salida
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    // Otra forma de configurar pines:
    // El bucle for se utiliza para configurar cada pin del array ledPins como salida
    //for (int i = 0; i < 4; i++) {
    //    pinMode(ledPins[i], OUTPUT);
    //}

}

/**
    * El loop se ejecuta continuamente despues de setup, y es donde se coloca el codigo que se desea ejecutar repetidamente.
     En este caso, se imprime "Hola Mundo" en el monitor serial cada segundo.
 */
void loop(){
    // TODO: Agregar una secuencia de encendido y apagado de los LEDs
    // ej: Enciendo LED1, espero 1 segundo, apago LED1, enciendo LED2, 
    //    espero 1 segundo, apago LED2, enciendo LED3, 
    //    espero 1 segundo, apago LED3 y repito la secuencia.

}