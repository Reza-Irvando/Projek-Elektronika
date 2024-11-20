// Pin untuk buzzer
const int buzzerPin = 12;

// Frekuensi nada dalam Hz
const int NOTE_E6 = 1319;
const int NOTE_D6 = 1175;
const int NOTE_F6 = 1397;
const int NOTE_G6 = 1568;
const int NOTE_C6 = 1047;
const int NOTE_A5 = 880;

// Melodi Nokia klasik
int melody[] = {
  NOTE_E6, NOTE_D6, NOTE_F6, NOTE_G6,
  NOTE_C6, NOTE_A5, NOTE_A5, NOTE_A5
};

// Durasi setiap nada (dalam milidetik)
int noteDurations[] = {
  150, 150, 150, 150,
  300, 300, 300, 300
};

void setup() {
  pinMode(buzzerPin, OUTPUT); // Atur pin buzzer sebagai output
}

void loop() {
  // Mainkan melodi Nokia klasik
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    tone(buzzerPin, melody[i], noteDurations[i]); // Mainkan nada
    delay(noteDurations[i]);                      // Tunggu selama durasi nada
  }

  noTone(buzzerPin); // Matikan buzzer setelah melodi selesai
  delay(5000);       // Tunggu sebelum mengulangi melodi
}
