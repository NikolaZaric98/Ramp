#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <Servo.h>
#include <Wire.h>
#define TrigPin 6 
#define EchoPin 7
#define ServoPin 9
#define RecvPin 2
Servo Servo1;
IRrecv IR(RecvPin);
LiquidCrystal_I2C lcd(0x27,16,2);
decode_results results;
void setup() {
  Serial.begin(9600);
  Servo1.attach(ServoPin);
  IR.enableIRIn();
  IR.blink13(true);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
lcd.setCursor(0,0);
 lcd.print("Kategorija:");
 String pom= String(results.value,HEX);
 Serial.println(pom);
if(pom=="ff6897" || pom=="ff9867"){ 
 lcd.setCursor(0,1);
 if(pom=="ff6897"){
  lcd.print("Putnicko");
  }
  if(pom=="ff9867"){
  lcd.print("Teretno");
  }
 Servo1.write(0);
   delay(4000);
for(int i=0;i<90;i++){
Servo1.write(i);
delay(30);
  }
 for(int i=90;i>0;i--){
Servo1.write(i);
delay(30);
  }}
  IR.resume();}
