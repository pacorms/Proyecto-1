int LED1 = 11;
int LED2 = 12;
int LED3 = 13;
int boton1 = 2;
int boton2 = 3;
int boton3 = 4;
int opcion = 0;
int aciertos = 0;
int errores = 0;
bool presionado;

//----------------------------------------------------------------------------------------------------------------------------

void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  
  randomSeed(analogRead(A0));
}

//----------------------------------------------------------------------------------------------------------------------------

void loop() {
  
  opcion = random(1, 4); 
  presionado = false;
  
  if (opcion == 1) digitalWrite(LED1, HIGH);
  else if (opcion == 2) digitalWrite(LED2, HIGH);
  else if (opcion == 3) digitalWrite(LED3, HIGH);
  
  while (!presionado) {
    
    if (digitalRead(boton1) == HIGH) {
      if (opcion == 1) {
        aciertos++;
        digitalWrite(LED1, LOW);
        presionado = true;
      }
      else errores++;
    }
    else if (digitalRead(boton2) == HIGH) {
      if (opcion == 2) {
        aciertos++;
        digitalWrite(LED2, LOW);
        presionado = true;
      }
      else errores++;
    }
    else if (digitalRead(boton3) == HIGH) {
      if (opcion == 3) {
        aciertos++;
        digitalWrite(LED3, LOW);
        presionado = true;
      }
      else errores++;
    }
  }
  
  while (digitalRead(boton1) == HIGH || digitalRead(boton2) == HIGH || digitalRead(boton3) == HIGH) {
    delay(10); 
  }

}

//----------------------------------------------------------------------------------------------------------------------------