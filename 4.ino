


#include <DHT.h>

// Definición de pines y parámetros del DHT11
#define pinSensorDHT 23
#define tipoDHT DHT11

// Pines para los LEDs
#define ledRojo 18     
#define ledVerde 2     
#define ledAzul 4      

// Inicialización del sensor DHT
DHT sensorClima(pinSensorDHT, tipoDHT);

void setup() {
  // Configuración de pines de los LEDs como salida
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  
  // Inicia la comunicación Serial
  Serial.begin(115200);
  
  // Inicializa el sensor DHT
  sensorClima.begin();
}

void loop() {
  // Lee la temperatura y la humedad del sensor
  float temp = sensorClima.readTemperature();
  float hum = sensorClima.readHumidity();

  // Imprime los valores en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" °C  -  Humedad: ");
  Serial.print(hum);
  Serial.println(" %");

  // Apagar todos los LEDs antes de evaluar condiciones
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);

  // Si la temperatura es menor de 20°C, activa el LED verde
  if (temp < 20) {
    digitalWrite(ledVerde, HIGH);
  }
  
  // Si la temperatura es mayor de 15°C, activa el LED azul
  if (temp > 15) {
    digitalWrite(ledAzul, HIGH);
  }
  
  // Si se cumplen ambas condiciones (temperatura entre >15 y <20°C) y además
  // la humedad es menor al 50%, activa el LED rojo
  if (temp < 20 && temp > 15 && hum < 50) {
    digitalWrite(ledRojo, HIGH);
  }
  
  // Espera 2 segundos antes de la siguiente lectura
  delay(2000);
}