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
  //Iniciamos los LEDs como salidas de nuestro Arduino.
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  //Iniciamos los botones como entradas de nuestro Arduino.
  pinMode(boton1, INPUT);
  pinMode(boton2, INPUT);
  pinMode(boton3, INPUT);
  
  randomSeed(analogRead(A0));
}

//----------------------------------------------------------------------------------------------------------------------------

void loop() {
  
  opcion = random(1, 4); //Genera el LED que se encenderá de forma random
  presionado = false; //Inicializamos la variable de control de presionado
  
  //Encendemos el LED correspondiente al número random generado:
  if (opcion == 1) digitalWrite(LED1, HIGH);
  else if (opcion == 2) digitalWrite(LED2, HIGH);
  else if (opcion == 3) digitalWrite(LED3, HIGH);
  
  while (!presionado) {//Iniciamos un ciclo aquí, este atrapa el programa aquí mientras el usuario no presione el botón.
    
    if (digitalRead(boton1) == HIGH) {//Evaluamos si el botón presionado fue el Boton 1.
      if (opcion == 1) {//Revisamos si el LED que estaba encendido era el 1 o no. En cuyo caso, el usuario acertó.
        aciertos++;//Agregamos 1 al contador de aciertos. Este contador se usará en futuras versiones del proyecto.
        digitalWrite(LED1, LOW);//Ya que el usuario acertó, apagamos el LED que estaba encendido.
        presionado = true;//Cambiamos el estado de la variable que controla nuestro ciclo while para poder salir.
      }
      else errores++;//Si el LED que estaba encendido no era el 1, el usuario se equivocó. Agregamos al contador de errores.
    }
    else if (digitalRead(boton2) == HIGH) {//Evaluamos si el botón presionado fue el Boton 2.
      if (opcion == 2) {//Revisamos si el LED que estaba encendido era el 2 o no. En cuyo caso, el usuario acertó.
        aciertos++;//Agregamos 1 al contador de aciertos. Este contador se usará en futuras versiones del proyecto.
        digitalWrite(LED2, LOW);//Ya que el usuario acertó, apagamos el LED que estaba encendido.
        presionado = true;//Cambiamos el estado de la variable que controla nuestro ciclo while para poder salir.
      }
      else errores++;//Si el LED que estaba encendido no era el 2, el usuario se equivocó. Agregamos al contador de errores.
    }
    else if (digitalRead(boton3) == HIGH) {//Evaluamos si el botón presionado fue el Boton 3.
      if (opcion == 3) {//Revisamos si el LED que estaba encendido era el 3 o no. En cuyo caso, el usuario acertó.
        aciertos++;//Agregamos 1 al contador de aciertos. Este contador se usará en futuras versiones del proyecto.
        digitalWrite(LED3, LOW);//Ya que el usuario acertó, apagamos el LED que estaba encendido.
        presionado = true;//Cambiamos el estado de la variable que controla nuestro ciclo while para poder salir.
      }
      else errores++;//Si el LED que estaba encendido no era el 3, el usuario se equivocó. Agregamos al contador de errores.
    }
  }
  
  //Pequeño ciclo while que ayuda a evitar que el programa lea el botón presionado múltiples veces y lo cuente como error:
  while (digitalRead(boton1) == HIGH || digitalRead(boton2) == HIGH || digitalRead(boton3) == HIGH) {
    delay(10); 
  }

}

//----------------------------------------------------------------------------------------------------------------------------
