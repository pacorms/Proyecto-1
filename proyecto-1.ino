//
int LED1=13;
int boton1=2;

void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(boton1,INPUT);
}

void loop()
{
  if (digitalRead(boton1) == HIGH) { 
    digitalWrite(LED1, LOW);
  } else {
    digitalWrite(LED1, HIGH);
  }
}