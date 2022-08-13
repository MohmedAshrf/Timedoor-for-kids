#include <Adafruit_LiquidCrystal.h>

int seconds = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  lcd_1.begin(16, 2);
  Display_Hello();
}

void Display_Hello(){
  	lcd_1.clear();
    lcd_1.setCursor(0, 0);
    lcd_1.print("Hello World");
}

void Display_10(){
    lcd_1.clear();
	lcd_1.setCursor(0, 0);
  	lcd_1.print("Turning LED ON");
  	lcd_1.setCursor(0, 1);
  	lcd_1.print(10);
}

void trun_LED_on(){
  	pinMode(2,OUTPUT);
  	digitalWrite(2, HIGH);
  	delay(1000);
  	digitalWrite(2, LOW);
  	Display_Hello();
}

void print_count(){
    lcd_1.setCursor(0, 1);
    lcd_1.print(seconds);
    delay(1000); // Wait for 1 second
    seconds += 1;
}

void loop()
{
  print_count();
  if (seconds == 10){
    Display_10();
    trun_LED_on();
    seconds=0;
  }
}
