#define yesil_led_pin 11
#define kirmizi_led_pin 10
#define motor_pin 9
#define nem_sensoru A0

#define calisma_siniri 600

int nem_degeri = 0;

void setup()
{
  pinMode(yesil_led_pin , OUTPUT);
  pinMode(kirmizi_led_pin , OUTPUT);
  pinMode(motor_pin , OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  nem_degeri = analogRead(nem_sensoru);
  
  if (nem_degeri > calisma_siniri)
  {
    digitalWrite(motor_pin, HIGH);
    digitalWrite(kirmizi_led_pin, HIGH);
    digitalWrite(yesil_led_pin, LOW);
    delay(3000);
    digitalWrite(motor_pin, LOW);
    delay(5000);
  }
  else
  {
    digitalWrite(yesil_led_pin, HIGH);
    digitalWrite(motor_pin, LOW);
    digitalWrite(kirmizi_led_pin, LOW);
  }
}
