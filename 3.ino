#define buzzerPin 22
#define pirPin 2

void setup()
{
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);  
  pinMode(pirPin, INPUT); 
}

void loop()
{
  int movimiento = digitalRead(pirPin);

  if (movimiento == HIGH) {
    digitalWrite(buzzerPin, HIGH); 
    Serial.println("¡Movimiento detectado!");
  }
  else {
    digitalWrite(buzzerPin, LOW); 
    Serial.println("¡Sin movimiento!");
  }

  delay(100);
}