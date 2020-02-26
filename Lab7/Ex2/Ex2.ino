#include<ThreeWire.h>
#include<RtcDS1302.h>
#include<SPI.h>
#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire,OLED_RESET);
ThreeWire myWire(4,5,3);
RtcDS1302<ThreeWire> Rtc(myWire);

void printDateTime(const RtcDateTime& dt)
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(dt.Year(),DEC);
  display.print('/');
  display.print(dt.Month(), DEC);
  display.print('/');
  display.print(dt.Day(), DEC);
  display.print(' ');
  display.print(dt.Hour(), DEC);
  display.print(':');
  display.print(dt.Minute(), DEC);
  display.print(':');
  display.print(dt.Second(), DEC);
  display.display();
}

void setup() 
{
  Rtc.Begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  RtcDateTime setting_time(2020,2,26,11,24,0);
  printDateTime(setting_time);
  Rtc.SetDateTime(setting_time);
}

void loop() 
{
  RtcDateTime now=Rtc.GetDateTime();
  printDateTime(now);
  delay(500);
}
