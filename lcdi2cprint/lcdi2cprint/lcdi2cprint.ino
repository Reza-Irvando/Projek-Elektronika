#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C dan ukuran layar
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ganti 0x27 dengan alamat I2C Anda

void setup() {
  // Inisialisasi LCD
  lcd.begin();
  lcd.backlight(); // Mengaktifkan lampu latar LCD
  
  // Menampilkan teks di layar
  lcd.setCursor(0, 0); // Baris 0, Kolom 0
  lcd.print("ADEL JELEEEK");
  lcd.setCursor(0, 1); // Baris 1, Kolom 0
  lcd.print("NGISINGAN D:<");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0, 0); // Baris 0, Kolom 0
  lcd.print("BOHOONG!");
  lcd.setCursor(0, 1); // Baris 1, Kolom 0
  lcd.print("ADEL CANTIK <3");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0); // Baris 0, Kolom 0
  lcd.print("TAPI TETEP");
  lcd.setCursor(0, 1); // Baris 1, Kolom 0
  lcd.print("NGISINGAN >:D");
  delay(3000);
  lcd.clear();
  lcd.print("WLEEE :P");
}

void loop() {
  
}
