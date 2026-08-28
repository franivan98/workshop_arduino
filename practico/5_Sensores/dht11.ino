// mostrar datos recibidos por un sensor DHT11 en el monitor serial

// Librerias
#include <DHT.h> // Libreria para el sensor DHT11   
#include <DHT_U.h> // Libreria para el sensor DHT11

// Definicion de Pines
#define DHTPIN 2 // Pin donde se conecta el sensor DHT11

// Definicion de variables
float temperatura = 0; // Variable para almacenar la temperatura
float humedad = 0; // Variable para almacenar la humedad

DHT dht(DHTPIN, DHT11); // Crea una instancia del sensor DHT11

void setup() {
    Serial.begin(9600); // Inicia la comunicacion serial a 9600 baudios
    dht.begin(); // Inicializa el sensor DHT11
}

void loop() {
    // Lee la temperatura y humedad del sensor DHT11
    temperatura = dht.readTemperature(); // Lee la temperatura en grados Celsius
    humedad = dht.readHumidity(); // Lee la humedad en porcentaje

    // Verifica si la lectura fue exitosa
    if (isnan(temperatura) || isnan(humedad)) {
        Serial.println("Error al leer el sensor DHT11");
        return;
    }

    // Imprime los valores de temperatura y humedad en el monitor serial
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C - Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");

    delay(2000); // Espera 2 segundos antes de la siguiente lectura
}