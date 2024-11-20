#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C dan ukuran layar
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti 0x27 dengan alamat I2C Anda

// Pin untuk sensor ultrasonik
#define TRIG_PIN 5
#define ECHO_PIN 18
const int led = 19;

void setup() {
  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight(); // Mengaktifkan lampu latar LCD

  // Inisialisasi Serial Monitor
  Serial.begin(115200);
  
  // Konfigurasi pin TRIG dan ECHO
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(led, OUTPUT);
  
  // Menampilkan pesan awal pada LCD
  lcd.setCursor(0, 0);
  lcd.print("HC-SR04 Distance");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Kirim sinyal trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca durasi sinyal pantulan
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Hitung jarak dalam cm
  float distance = (duration * 0.034) / 2;

  // Menampilkan jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Menampilkan jarak di LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:       ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm      ");
  if(distance < 10){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  
  delay(500); // Delay untuk pembaruan data
}
