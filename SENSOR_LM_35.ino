#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);


const int sensor = A0; //Sensor di hubungkan ke pin A0
const int kipas = 7;      // inisialisasi kipas pin pada 7
const int buzzer = 2;     // inisialisasi buzzer pin pada 2

float suhu;

void setup() {
  Serial.begin (9600);  //koding menyalakan serial monitor
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode (sensor, INPUT); // Jadikan sensor sebagai input analog
  pinMode(buzzer, OUTPUT);  // Untuk menentukan pin buzzer sebagai output
  pinMode(kipas, OUTPUT);  // Untuk menentukan pin kipas sebagai output
digitalWrite(buzzer, LOW);
digitalWrite(kipas, HIGH);
  
}

void loop() {
  //Baca temperatur dari LM35
  int nilaiDigital = analogRead (sensor);

  //Konversi ke derajat celcius
  suhu = (5.0 * nilaiDigital * 100.0)/1024.0;

  //tampilkan ke serial monitor
  Serial.print ("Temperatur:  ");
  Serial.print (suhu);
  Serial.println ("C");
  delay (300); //delay 300ms

  //Program menyalakan 
  //jika suhu ruangan lebih dari 37 celcius, nyalakan 
  if (suhu > 37.00){
  digitalWrite(buzzer, HIGH); 
  digitalWrite(kipas, LOW);
  lcd.setCursor(0, 0);
  lcd.print("Temperatur : ");
  lcd.print(suhu);
  lcd.print("C");
  lcd.setCursor(2, 1);
  lcd.print("Ruang Panas");
  delay(4000);
  lcd.clear();
  }
  
  //jika tidak padam
  else {
  digitalWrite(buzzer, LOW); 
  digitalWrite(kipas, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Temperatur : ");
  lcd.print(suhu);
  lcd.print("C");
  lcd.setCursor(2, 1);
  lcd.print("Ruang Sejuk");
  delay(2000);
  lcd.clear();
  
  }
}
