#include<LiquidCrystal.h>
#include <SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);               // sets the interfacing pins

const int irs = 7;
const int led = 8;
int detect;
static int count = 0;

SoftwareSerial PHdis(9, 10);                        //rx,tx 

void setup()
{
  
  lcd.begin(16, 2);  
  pinMode (irs, INPUT);
  pinMode (led, OUTPUT); 
  
  Serial.begin (9600);
  PHdis.begin(9600);
}

void loop()
{
  detect = digitalRead (irs);
  Serial.println(detect);
  if (detect == HIGH)
  {
    digitalWrite (led, LOW);
  }
  else
  {   
     count=count+1;
     digitalWrite(led, HIGH);
     delay(100);
     digitalWrite(led, LOW);
     delay(100); 
     lcd.setCursor(0,0);           
     lcd.print("NUMBER: ");
     lcd.print(count);             
     
     PHdis.print(count);
     PHdis.print(";");
    
     delay (200);
  }
}
