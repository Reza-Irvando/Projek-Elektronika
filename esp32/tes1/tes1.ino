#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493
#define T_C1 523

const int C = 15;
const int D = 16;
const int E = 17;
const int F = 5;
const int G = 18;
const int A = 19;
const int B = 27;
const int C1 = 26;

const int Buzz = 25;

void setup()
{
  pinMode(C, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(F, INPUT_PULLUP);
  pinMode(G, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
  pinMode(C1, INPUT_PULLUP);
  pinMode(Buzz, OUTPUT);
}

void loop()
{ 
  while(digitalRead(C) == LOW)
  {
    tone(Buzz,T_C,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(D) == LOW)
  {
    tone(Buzz,T_D,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(E) == LOW)
  {
    tone(Buzz,T_E,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(F) == LOW)
  {
    tone(Buzz,T_F,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(G) == LOW)
  {
    tone(Buzz,T_G,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(A) == LOW)
  {
    tone(Buzz,T_A,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(B) == LOW)
  {
    tone(Buzz,T_B,10);
    digitalWrite(Buzz, LOW);
  }

  while(digitalRead(C1) == LOW)
  {
    tone(Buzz,T_C1,10);
    digitalWrite(Buzz, LOW);
  }

  noTone(Buzz);

}