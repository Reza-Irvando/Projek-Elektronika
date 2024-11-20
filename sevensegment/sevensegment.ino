#include <TM1637Display.h>

// Pin CLK dan DIO
#define CLK 19  // Pin CLK
#define DIO 18  // Pin DIO

// Inisialisasi TM1637
TM1637Display display(CLK, DIO);

void setup() {
  // Inisialisasi serial monitor
  Serial.begin(115200);
  
  // Atur kecerahan tampilan (0-7)
  display.setBrightness(7);

  // Tampilkan angka awal
  display.showNumberDec(1234); // Menampilkan angka 1234
}

void loop() {
  // Contoh: Menampilkan angka yang terus bertambah setiap detik
  static int counter = 0;
  display.showNumberDec(counter, false); // Menampilkan angka dengan leading zero false
  delay(1000); // Tunggu 1 detik
  counter++;
  
  if (counter > 9999) {
    counter = 0; // Reset ke 0 jika lebih dari 4 digit
  }
}
