// Mostraremos por un LCD I2C minutos y segundos.

// Librerias
#include <Wire.h> // Libreria para comunicacion I2C
#include <LiquidCrystal_I2C.h> // Libreria para LCD I2C

// Definicion de Pines
// El LCD I2C se conecta a los pines SDA y SCL del Arduino. En la mayoría de las placas, 
// estos pines son A4 (SDA) y A5 (SCL) en el Arduino Uno, pero pueden variar dependiendo del 
// modelo de placa que estés utilizando.

// Definicion de variables
LiquidCrystal_I2C lcd(0x27, 16, 2); // Configura el LCD con la direccion I2C (0x27) y
//  el tamaño (16 columnas y 2 filas)


unsigned long startTime; // Variable para almacenar el tiempo de inicio del cronometro
unsigned long elapsedTime; // Variable para almacenar el tiempo transcurrido

void setup() {
    lcd.init(); // Inicializa el LCD
    lcd.backlight(); // Enciende la luz de fondo del LCD
    startTime = millis(); // Almacena el tiempo de inicio del cronometro
    wire.begin(); // Inicia la comunicacion I2C
}

void loop() {
    elapsedTime = millis() - startTime; // Calcula el tiempo transcurrido

    // Convertir el tiempo transcurrido a minutos y segundos
    int minutes = elapsedTime / 60000;
    int seconds = (elapsedTime % 60000) / 1000;

    // Mostrar el tiempo en el LCD
    lcd.setCursor(0, 0);
    lcd.print("Cronometro");
    lcd.setCursor(0, 1);
    lcd.print(minutes);
    lcd.print(":");
    if (seconds < 10) {
        lcd.print("0");
    }
    lcd.print(seconds);
}