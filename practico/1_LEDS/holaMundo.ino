//Hola Mundo en Arduino

//Librerias

//Definicion de Pines

//Definicion de variables

/**
    * El setup se ejecuta una sola vez al iniciar el programa
     y se utiliza para configurar los pines, iniciar la comunicacion serial, etc.
 */
void setup(){
    Serial.begin(9600); //Inicia la comunicacion serial a 9600 baudios
}

/**
    * El loop se ejecuta continuamente despues de setup, y es donde se coloca el codigo que se desea ejecutar repetidamente.
     En este caso, se imprime "Hola Mundo" en el monitor serial cada segundo.
 */
void loop(){
    Serial.println("Hola Mundo"); //Imprime "Hola Mundo" en el monitor serial
    delay(1000); //Espera 1 segundo antes de repetir el loop
}