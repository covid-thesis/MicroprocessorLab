#include <SPI.h>
#define DATA_PIN 11
#define CLOCK_PIN 13
#define SS_PIN_1 10
#define SS_PIN_2 9

#define up 2
#define down 3
#define zero 4

uint8_t segment_no[10] = {0x3F ,
                          0x06,                          
                          0x5B,
                          0x4F,
                          0x66,
                          0x6D,
                          0x7D,
                          0x07,
                          0x7F,
                          0x6F
                          };
unsigned char fn(int a){
  int b = segment_no[a];
  return b;
}

void spi_write_1 (int bData)
{
  unsigned char cData = fn(bData);
shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);    
    digitalWrite(SS_PIN_1, HIGH);
    digitalWrite(SS_PIN_1, LOW);
    }
void spi_write_2 (int bData)
{unsigned char cData = fn(bData);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, cData);   
digitalWrite(SS_PIN_2, HIGH);
    digitalWrite(SS_PIN_2, LOW);
    }

void num(int a){
 int  oneth = a%10;
 int tenth = (a/10)%10;
  spi_write_1(tenth);
    spi_write_2 (oneth);
}

void setup()
{
pinMode(SS_PIN_1, OUTPUT);
   pinMode(SS_PIN_2, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(zero, INPUT);
  pinMode(6,OUTPUT);
}
int n = 0;
void loop()
{
  
  num(n);
  if(digitalRead(up)==0){n++;delay(500);}
  if(digitalRead(down)==0){n--;delay(500);}
  if(digitalRead(zero)==0){n=0;tone(6,1500,1000);}
   
}
