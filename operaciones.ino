int modo = -1;

void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 if (digitalRead(5))
 {
  modo = cambiarModo(modo);
 }

  switch (modo)
  {
    case 0:
      suma();
    break;
    case 1:
      resta();
    break;
    case 2:
      multiplicacion();
    break;
    case 3:
      division();
    break;
    case 4:
      And();
    break;
    case 5:
      Or();
    break;
    case 6:
      Xor();
    break;
    case 7:
      Not();
    break;
  }
}

int cambiarModo(int modo)
{
  if (modo < 7)
  {
    modo++;
    delay(1000);
  }
  else
  {
    modo = 0;
    delay(1000);
    return 0;
  }
  return modo;
}


void suma()
{
  if (digitalRead(6) ^ digitalRead(7))
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);

  if (digitalRead(6) && digitalRead(7))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
}

void resta()
{
  int btn1 = digitalRead(6);
  int btn2 = digitalRead(7);

  if (btn2 == HIGH && btn1 == LOW)
    digitalWrite(8, HIGH);
  else
    digitalWrite(8, LOW);

  if (btn1 == HIGH && btn2 == LOW)
  {
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
  } 
}

void multiplicacion()
{
  if (digitalRead(6) && digitalRead(7))
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
}

void division()
{
  int btn1 = digitalRead(6);
  int btn2 = digitalRead(7);

  if (btn1 == HIGH && btn2 == HIGH)
  {
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  }

  if (btn1 == LOW && btn2 == LOW)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9,LOW);
  }

  
  if (btn1 == HIGH && btn2 == LOW)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }
}

//Compuertas logicas
void And()
  {
    if (digitalRead(6) && digitalRead(7))
    {
      digitalWrite(8, HIGH);
    } 
    else
    {
      digitalWrite(8, LOW);
    }
  }

  void Or()
  {
    if (digitalRead(6) || digitalRead(7))
    {
      digitalWrite(8, HIGH);
    } 
    else
    {
      digitalWrite(8, LOW);
    }
  }

  void Xor()
  {
    if (digitalRead(6) ^ digitalRead(7))
    {
      digitalWrite(8, HIGH);
    } 
    else
    {
      digitalWrite(8, LOW);
    }
  }

  void Not()
  {
    if (!digitalRead(6))
    {
      digitalWrite(8, HIGH);
    } 
    else
    {
      digitalWrite(8, LOW);
    }
  }