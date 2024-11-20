#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493

const int led = 23; // Arduino pin connected to button's pin


void setup() {
  pinMode(led, OUTPUT);       // set arduino pin to output mode
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
