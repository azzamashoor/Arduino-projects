#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 4, 5, 6, 7, 8);

#define sensorPin3 9
#define sensorPin4 10
const int buzzer = 12;

int sensorState3 = 0;
int sensorState4 = 0;
int count=0;

void setup()
{
 pinMode(buzzer, OUTPUT); 
  pinMode (sensorPin3, INPUT_PULLUP);
  pinMode (sensorPin4, INPUT_PULLUP);
   lcd.begin(16,2);
  
  
   lcd.setCursor(0,1);
  lcd.print("Empty");
  delay(200);
   
}

void loop()
{  
  
  sensorState3 = digitalRead(sensorPin3);
  sensorState4 = digitalRead(sensorPin4);
 
  if(sensorState4  == LOW){
    count++; 
    delay(500);
  }
 if(sensorState3  == LOW){
    count--; 
    delay(500);
  }

   if(count<=0)
  {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Smart Shelf");
    lcd.setCursor(0,1);
    lcd.print("Empty");
    
   
    
  }
  else if (count>0 && count<10){
    lcd.setCursor(1,0);
    lcd.print("Smart Shelf");
    lcd.setCursor(0,1);
    lcd.print("Products:   ");
    lcd.setCursor(12,1);
    lcd.print(count);
    lcd.setCursor(13,1);
    lcd.print("  "); 
    
  }
  else {
    
    lcd.setCursor(0,1);
    lcd.print("Products:   ");
    lcd.setCursor(12,1);
    lcd.print(count);  
    
  }
}
