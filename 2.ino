// Definición de pines
#define LED_ROJO   18     // Componente rojo del LED RGB
#define LED_VERDE  4      // Componente verde del LED RGB
#define LED_AZUL   2      // Componente azul del LED RGB
#define SENSOR_PIN 15     // Pin al que se conecta la salida analógica del fotoresistor

// Definición de umbrales
// Si el valor del sensor es superior a umbralAlto, significa luz suficiente y se apaga el LED.
int umbralAlto  = 3000;   // Luz alta
int umbralMedio = 2000;   // Luz moderada
int umbralBajo  = 1000;   // Muy poca luz

void setup() {
  // Configuración de pines de salida para cada color del LED RGB
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  
  // Configuración del pin del sensor
  pinMode(SENSOR_PIN, INPUT);
  
  // Inicializamos la comunicación serial para depurar los valores del sensor
  Serial.begin(115200);
}

void loop() {
  // Leemos el valor del fotoresistor
  int valorLuz = analogRead(SENSOR_PIN);
  Serial.print("Nivel de luz: ");
  Serial.println(valorLuz);
  
  // Si hay suficiente luz, se apagan todos los LED
  if (valorLuz > umbralAlto) {
    analogWrite(LED_ROJO, 0);
    analogWrite(LED_VERDE, 0);
    analogWrite(LED_AZUL, 0);
  }
  // En luz moderada, se enciende el LED verde
  else if (valorLuz <= umbralAlto && valorLuz > umbralMedio) {
    analogWrite(LED_ROJO, 0);
    analogWrite(LED_VERDE, 255);
    analogWrite(LED_AZUL, 0);
  }
  // Con luz baja, se encienden LED azul
  else if (valorLuz <= umbralMedio && valorLuz > umbralBajo) {
    analogWrite(LED_ROJO, 0);
    analogWrite(LED_VERDE, 0);
    analogWrite(LED_AZUL, 255);
  }
  // En muy baja intensidad de luz, se enciende LED rojo
  else if (valorLuz <= umbralBajo) {
    analogWrite(LED_ROJO, 255);
    analogWrite(LED_VERDE, 0);
    analogWrite(LED_AZUL, 0);
  }
  
  // Pequeño retardo para estabilizar la lectura
  delay(100);
}