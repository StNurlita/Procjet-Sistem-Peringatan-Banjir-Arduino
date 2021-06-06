#define pinSensor A0
int nilaiMax = 1023; // nilai "sensorValue" saat sensor terendam penuh kedalam air, bisa dirubah sesuai sensor dan jenis air yang dipakai
int sensorValue = 0; // variable untuk menampung nilai baca dari sensor dalam bentuk integer
float tinggiAir = 0; // variabel untuk menampung ketinggian air
float sensorVoltage = 0; // untuk menampung nilai ketinggian air
float panjangSensor = 4.0 ; // 4.0 cm, bisa dirubah, menyesuikan dengan panjang sensor yang digunakan
int led1 = 11;
int led2 = 12;
int led3 = 13;


void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  sensorValue = analogRead(pinSensor); // membaca tengan dari sensor dalam bentuk integer
  tinggiAir = sensorValue * panjangSensor / nilaiMax;
  sensorVoltage = sensorValue * 5.0 / 1023;

  Serial.print("Sensor Value = ");
  Serial.println(sensorValue);
  Serial.print("Sensor Voltage = ");
  Serial.println(sensorVoltage);
  Serial.print("Tinggi Air = ");
  Serial.println(tinggiAir);
  Serial.println();
  delay(1000);

  if (tinggiAir <= 0.70) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (tinggiAir <= 1.00) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
}
