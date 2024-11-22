/*Sonette_ISIM*/
// 53s
#include<Wire.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
const int BUTTON_PIN = 6;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
DS3231  rtc(SDA, SCL);
Time t;
void setup() { 
  
   Serial.begin(115200);
   rtc.begin();
    // rtc.setDOW(FRIDAY);    
    // rtc.setTime(18, 36, 00);    
    // rtc.setDate(22, 11, 2024); 
    lcd.begin(16,2);
    pinMode(5, OUTPUT);
pinMode(BUTTON_PIN, INPUT_PULLUP);       
}

void loop() {
  
t = rtc.getTime();
 lcd.setCursor(0,0);
 lcd.print("Temps: ");
 lcd.print(rtc.getTimeStr());
 lcd.setCursor(0,1);
 lcd.print("Date: ");
 lcd.print(rtc.getDateStr());
 
digitalWrite(5,HIGH);  
  
jour_son(1);
 jour_son(2);
  jour_son(3);
   jour_son(4);
    jour_son(6);
     vendredi_son();
     
      int buttonState = digitalRead(BUTTON_PIN); 

  if (buttonState == LOW) {
    digitalWrite(5, LOW); 
  }
  else
  if (buttonState == HIGH) {
    digitalWrite(5, HIGH);  
  }
}


void son(int d, int h , int m , int s){

  if(t.dow == d && t.hour==h && t.min ==m && t.sec == s)  
{
digitalWrite(5,LOW);
delay(4000);
digitalWrite(5,HIGH);
}
}

//************************************lundi ----- Samedi**********************************
void jour_son(int j){

son(j,8,20,0);
 son(j,8,30,0);
  //son(j,10,30,0);
   son(j,10,55,0);
    son(j,11,10,0);
     //son(j,11,30,0);
     // son(j,12,30,0);
       son(j,13,30,0);
     // son(j,14,30,0);
    // son(j,15,30,0);
    son(j,16,0,0);
   son(j,16,15,0);
 // son(j,16,30,0);
 //son(j,17,30,0);
son(j,18,30,0);

  }
  
//************************************vendredi**********************************
  void vendredi_son(void){

son(5,8,20,0);
 son(5,8,30,0);
  son(5,10,20,0);
   son(5,10,35,0);
   // son(5,11,30,0);
    // son(5,12,30,0);
      son(5,13,30,0);
    // son(5,14,30,0);
   // son(5,15,30,0);
   son(5,16,30,0);
  son(5,16,45,0);
// son(5,17,30,0);
son(5,18,30,0);

}


/*                                          RAMADAN
///************************************lundi ----- Samedi**********************************
void jour_son(int j){

//son(j,23,2,0);  //essai

son(j,8,30,0);
 son(j,9,30,0);
  son(j,10,30,0);
   son(j,10,55,0);
    son(j,11,10,0);
     son(j,11,30,0);
      son(j,12,30,0);
       son(j,13,30,0);
      son(j,14,30,0);
     son(j,15,30,0);
    son(j,16,0,0);
   son(j,16,15,0);
  son(j,16,30,0);
 son(j,17,30,0);
son(j,18,30,0);  

  }

//************************************vendredi**********************************
  void vendredi_son(void){

son(5,8,30,0);
 son(5,9,30,0);
  son(5,10,20,0);
   son(5,10,35,0);
    son(5,11,30,0);
     son(5,12,30,0);
      son(5,13,30,0);
     son(5,14,30,0);
    son(5,15,30,0);
   son(5,16,30,0);
  son(5,16,45,0);
 son(5,17,30,0);
son(5,18,30,0);

}
*/
