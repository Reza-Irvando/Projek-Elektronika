#include <Wire.h>
#include "RTClib.h"
#include <TM1637Display.h>
#include <LiquidCrystal_I2C.h>

// Pin CLK dan DIO
#define CLK 19  // Pin CLK
#define DIO 18  // Pin 
const int buzzer = 12;

RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD bisa 0x27 atau 0x3F

// Inisialisasi TM1637
TM1637Display display(CLK, DIO);

const uint8_t loading[] = {
    0b01000000,  // Digit kosong
    0b01000000,  // Tanda minus (-)
    0b01000000,  // Digit kosong
    0b01000000   // Digit kosong
  };

bool colonState = false;  // Status berkedip titik dua

void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);
  lcd.begin();
  lcd.backlight();  // Aktifkan backlight LCD
  lcd.clear();
  display.setBrightness(5);  // Atur kecerahan (0-7)
  display.setSegments(loading);
  // Inisialisasi RTC
  if (!rtc.begin()) {
    Serial.println("RTC tidak ditemukan!");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC tidak berjalan, mengatur waktu awal...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Sinkronisasi dengan waktu kompilasi
  }

  Serial.println("RTC dan TM1637 Siap!");
}

void loop() {
  DateTime now = rtc.now();
  Serial.print(now.year()); Serial.print('/');
  Serial.print(now.month()); Serial.print('/');
  Serial.print(now.day()); Serial.print(" ");
  Serial.print(now.hour()); Serial.print(':');
  Serial.print(now.minute()); Serial.print(':');
  Serial.println(now.second());
  
  // Mendapatkan jam dan menit
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();
  
  // Menggabungkan jam dan menit
  int displayTime = (hour * 100) + minute;

  // LCD clear ketika ganti hari
  if(hour == 0 && minute == 0 && second == 0){
    lcd.clear();
  }
  
  // Menampilkan hari dalam minggu
  lcd.setCursor(0, 0);
  lcd.print("Hari: ");
  lcd.print(getDayOfWeek(now.dayOfTheWeek()));
  
  // Menampilkan tanggal
  lcd.setCursor(0, 1);
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  

  // Toggle status titik dua untuk berkedip
  colonState = !colonState;

  // Menampilkan waktu dengan titik dua berkedip
  display.showNumberDecEx(displayTime, colonState ? 0b01000000 : 0, true); // 0b01000000 untuk titik dua

  if(second == 0 && minute == 0 && 8 < hour < 21 ){
    digitalWrite(buzzer, HIGH);
    delay(2000);
  } else{
    digitalWrite(buzzer, LOW);
  }
    
  delay(1000);  // Tunggu 1 detik
}

String getDayOfWeek(uint8_t day) {
  switch (day) {
    case 0: return "Minggu";
    case 1: return "Senin";
    case 2: return "Selasa";
    case 3: return "Rabu";
    case 4: return "Kamis";
    case 5: return "Jumat";
    case 6: return "Sabtu";
    default: return "";
  }
}
