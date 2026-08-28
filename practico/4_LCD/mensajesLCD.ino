// Mostraremos mensajes aleatorios por un LCD I2C.

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

String mensajes[] = {"Hola Mundo!", "Arduino es genial!", "LCD I2C", "Programacion en C++"};

void setup() {
    lcd.init(); // Inicializa el LCD
    lcd.backlight(); // Enciende la luz de fondo del LCD
    Wire.begin(); // Inicia la comunicacion I2C
}

void loop(){
    int indice = random(0, 4); // Genera un numero aleatorio entre 0 y 4
    lcd.clear(); // Limpia la pantalla del LCD
    lcd.setCursor(0, 0); // Establece el cursor en la primera columna de la primera fila
    lcd.print(mensajes[indice]); // Muestra el mensaje aleatorio en el LCD
    delay(2000); // Espera 2 segundos antes de mostrar el siguiente mensaje
}