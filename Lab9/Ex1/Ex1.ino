#define LED_PIN_0 9
#define INT_PIN   3

int toggle=1;
int count=0;

void setup()
{
  pinMode(LED_PIN_0, OUTPUT);
  pinMode(INT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), 
                  ISR_Callback, FALLING);
  // RISING    : 0v to 5v
  // FALLING  : 5v to 0v
  // CHANGE   : 0v to 5v or 5v to 0v
  Serial.begin(9600);
}

void loop()
{
    if(count ==0)
    {
      digitalWrite(LED_PIN_0, HIGH);
      delay(1000);
      digitalWrite(LED_PIN_0, LOW);
      delay(1000);
      Serial.println("1");
    }
  if(count ==1)
    {
      digitalWrite(LED_PIN_0, HIGH);
      delay(2000);
      digitalWrite(LED_PIN_0, LOW);
      delay(2000);
    Serial.println("2");
    }
  if(count ==2)
    {
      digitalWrite(LED_PIN_0, HIGH);
      delay(3000);
      digitalWrite(LED_PIN_0, LOW);
      delay(3000);
    Serial.println("3");
    }
}

void ISR_Callback()
{
  digitalWrite(LED_PIN_0, toggle);
    count++;
  //toggle++;
  //toggle = !toggle;
  Serial.println("Called");
}
