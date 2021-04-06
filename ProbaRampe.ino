#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>    //
#define ServoPin 9
LiquidCrystal_I2C lcd(0x27,16,2);
Servo Servo1;
/*void setup() {
   Servo1.attach(ServoPin);
}

void loop() {Servo1.write(0);
   delay(4000);
for(int i=0;i<90;i++){
Servo1.write(i);
delay(30);
  }
}*/
#include <IRremote.h>
#define RecvPin 7
#define TrigPin 6 
#define EchoPin 5
#define Red 12
#define Green 11
IRrecv IR(RecvPin);
decode_results results;
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  IR.blink13(true);
 Servo1.attach(ServoPin);
 pinMode(TrigPin,OUTPUT);
 pinMode(EchoPin,INPUT);
 pinMode(Red,12);
 pinMode(Green,11);
   lcd.init();
  lcd.backlight();
}

void loop(){
  digitalWrite(Red,HIGH);
  digitalWrite(Green,LOW);
  if(IR.decode(&results)){
  String pom= String(results.value,HEX);
  Serial.println(pom);
  int prosao=0;
  if(pom=="ff6897" || pom=="ff9867"){
    digitalWrite(Red,LOW);
  digitalWrite(Green,HIGH);
   lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Kategorija:");
     lcd.setCursor(0,1);
if(pom=="ff6897" ){
      lcd.print("Putnicko");
      delay(1000);
      lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Cena:");
 lcd.setCursor(0,1);
      lcd.print("100");
      }    
if(pom=="ff9867"){
      lcd.print("Teretno");
       delay(1000);
      lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Cena:");
 lcd.setCursor(0,1);
      lcd.print("290");}
 Serial.println(1);
   for(int i=0;i<90;i++){
Servo1.write(i);
delay(30);
  }
    delay(3000);
    while(prosao==0){
digitalWrite(TrigPin,LOW);
delayMicroseconds(2);
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
 digitalWrite(TrigPin,LOW);
long duration = pulseIn(EchoPin, HIGH);
    int distance= duration*0.034/2;
    if (distance>20){
      prosao=1;
      Serial.println("PROSAO");
     }
    }
     lcd.clear();}
    if(prosao==1){
    for(int i=90;i>0;i--){
Servo1.write(i);
delay(30);
  }}
  IR.resume();}
  }
