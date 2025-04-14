int buzzer = 14; //buzzer
int potenciometro = 34; //potenciometro
int ledverde=26;
int ledrojo=25;
int ledazul=27;
float valor; // 
int Fmin= 100; // frecuencias a las que quieres osile el sonido
int Fmax = 5000;

void setup() {
  pinMode(ledverde, OUTPUT);//delcaracion de led verde como salida
  pinMode(ledrojo, OUTPUT);//declaracion de led rojo como salida
  pinMode(ledazul, OUTPUT);//delcaracion de led azul como salida
pinMode(buzzer, OUTPUT); // declaracion de la variable como salida
pinMode(potenciometro, INPUT); // declaracion de la variable como entrada
}

void loop() {
valor = analogRead(potenciometro);
float brillo=map(valor,0,1023,0,255);//mapeamos el valor entre 0 y 255 de nuestro led
float frecuencia = map(valor, 0, 1023, Fmin, Fmax);//reducimos los valores del potenciometro 
analogWrite(buzzer,frecuencia);
 if (brillo<100){analogWrite(ledverde,brillo);}
 if (brillo>100 && brillo<200){analogWrite(ledrojo,brillo);}
else {analogWrite(ledazul,brillo);}

//delay(500);

}
