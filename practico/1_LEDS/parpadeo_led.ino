// Parpadeo de LED utilizando delay y millis

//Librerias

//Definicion de Pines
const int ledPin = 13; //Pin del LED integrado en la placa

//Definicion de variables

/**
    * El setup se ejecuta una sola vez al iniciar el programa
    * y se utiliza para configurar los pines, iniciar la comunicacion serial, etc.
 */

// Funciones


void setup(){
    pinMode(ledPin, OUTPUT); //Configura el pin del LED como salida
}

/**
    * El loop se ejecuta continuamente despues de setup, y es donde se coloca el codigo que se desea ejecutar repetidamente.
    *En este caso, se imprime "Hola Mundo" en el monitor serial cada segundo.
 */
void loop(){
    //TODO: Encender y apagar el LED conectado al pin 13 cada 1 segundo.
}

