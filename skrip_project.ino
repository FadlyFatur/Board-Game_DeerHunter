//tambah timer & waktu habis

#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
#include <Servo.h> // menyertakan library servo ke dalam program 

Servo myservo1;     // variable untuk menyimpan posisi data
Servo myservo2;
Servo myservo3; 
Servo myservo4;
Servo myservo5;
int pos = 90;
int nilai;

int x = 0;  //setting timer 
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

const int pinReceiver1 = 9;
const int pinReceiver2 = 10;
const int pinReceiver3 = 11;
const int pinReceiver4 = 12;
const int pinReceiver5 = 13;
int pinservo1 = 2;
int pinservo2 = 3;
int pinservo3 = 4;
int pinservo4 = 5;
int pinservo5 = 6;

void setup() {
 myservo1.attach(pinservo1);
 myservo2.attach(pinservo2);
 myservo3.attach(pinservo3);
  myservo4.attach(pinservo4);
  myservo5.attach(pinservo5);

 pinMode(pinReceiver1, INPUT);
 pinMode(pinReceiver2, INPUT);
 pinMode(pinReceiver3, INPUT);
 pinMode(pinReceiver4, INPUT);
  pinMode(pinReceiver5, INPUT);
 pinMode(pinservo1, OUTPUT);
 pinMode(pinservo2, OUTPUT);
 pinMode(pinservo3, OUTPUT);
 pinMode(pinservo4, OUTPUT);
 pinMode(pinservo5, OUTPUT);
 Serial.begin(9600);

  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
 
  lcd.setCursor(0,0);
  lcd.print("   Permainan");
//  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("-Laser Target-");
  lcd.setCursor(15,0);
  lcd.print("3");
  delay(1000);
  lcd.setCursor(15,0);
  lcd.print("2");
  delay(1000);
  lcd.setCursor(15,0);
  lcd.print("1");
  delay(1000);
  lcd.setCursor(14,0);
  lcd.print("GO");
  delay(1000);
  lcd.clear();
  lcd.print("SKOR : 0");

}

void poinPlus(){
  nilai = nilai + 10;
//  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("+10");
  delay(500);
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SKOR : ");
//  delay(50);
  lcd.setCursor(7,0);
  lcd.print( nilai );
  lcd.setCursor(0,1);
  lcd.print("   ");
}

void poinMin(){
    nilai = nilai + 25;
//    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("+25");
   delay(500);
//    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SKOR : ");
//    delay(50);
    lcd.setCursor(7,0);
    lcd.print( nilai );
    lcd.setCursor(0,1);
    lcd.print("   ");
}

void ser1() {
      for(pos = 00; pos < 90; pos += 2)
      {
         
         myservo1.write(pos);
        delay(15);
      }
      delay(500);
//      for(pos = 90; pos>=0; pos-=2)
//      {                              
//        myservo1.write(pos);             
//        delay(55);                        
//      }
}

void ser2() {
      for(pos = 00; pos < 90; pos += 2)
      {
         myservo2.write(pos);
        delay(15);
      }
      delay(500);
}

void ser3() {
      for(pos = 00; pos < 90; pos += 2)
      {
         myservo3.write(pos);
        delay(15);
      }
      delay(500);
}

void ser4() {
      for(pos = 00; pos < 90; pos += 2)
      {
         myservo4.write(pos);
        delay(15);
      }
      delay(500);
}

void ser5() {
      for(pos = 00; pos < 90; pos += 2)
      {
         myservo5.write(pos);
        delay(15);
      }
      delay(500);
}

void loop() {
  int value1 = digitalRead(pinReceiver1);
  int value2 = digitalRead(pinReceiver2);
  int value3 = digitalRead(pinReceiver3);
  int value4 = digitalRead(pinReceiver4);
  int value5 = digitalRead(pinReceiver5);

    if (value1 == 1){
      digitalWrite(pinservo1,LOW);
      poinPlus();
      ser1();   
    }  
      else if (value2 == 1){
//      digitalWrite(pinservo2,HIGH);
//      delay(100);
      digitalWrite(pinservo2,LOW);
      poinPlus();
      ser2();  
    }  
     else if (value3 == 1){
      digitalWrite(pinservo3,LOW);
      poinPlus();
      ser3();  
    } 
     else if (value4 == 1){
      digitalWrite(pinservo4,LOW);
      poinMin();
      ser4();  
    } 
      else if (value5 == 1){
      digitalWrite(pinservo5,LOW);
      poinMin();
      ser5();  
    } 
    else if (x>=120){ //mengakhiri game jika waktu habis
      Gameover();
    }else{
      delay(1000);
    }
      
     x=x+1;
    lcd.setCursor(13,0);
    lcd.print(x);
    Serial.println(x); // meliat timer di serial monitor *tdk ditampilkan di LCD

}



void Gameover(){ //fungsi mengakhiri looping game
  lcd.clear();
  while(true){
  lcd.setCursor(0,0);
  lcd.print("Waktu Habis!");
  lcd.setCursor(0,1);
  lcd.print("Skor : ");
  lcd.setCursor(7,1);
  lcd.print(nilai);
  }
}

