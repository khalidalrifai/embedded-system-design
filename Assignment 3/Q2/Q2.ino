unsigned char *ddrd = (unsigned char *)0x2A;

unsigned char *tccr2a = (unsigned char *)0xb0;
unsigned char *tccr2b = (unsigned char *)0xb1;

void setup()
{
  *ddrd = 1 << 3;
  *tccr2a = 0b00100000;         // Phase Correct PWM 0xFF & Normal Output
  *tccr2b = 0b00001100;         // Pre-Scaler 64
  
  double counter;
  Serial.begin(9600);

  for (;;)
  {
    counter = 0;
    
    while(counter < 255)
    {
      counter+=0.85;
      Serial.println(counter);
      analogWrite(3, counter);  // PWM at OC2B
      delay(11);    // Sampling period = (1/90.91) = 10.99989 ms which is almost 11 ms
    }
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
