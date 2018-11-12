unsigned char *ddrb = (unsigned char *)0x24;

unsigned char *tccr1a = (unsigned char *)0x80;
unsigned char *tccr1b = (unsigned char *)0x81;
unsigned char *tccr1c = (unsigned char *)0x82;
unsigned char *ocr1ah = (unsigned char *)0x88;
unsigned char *ocr1al = (unsigned char *)0x89;

void setup()
{
  *tccr1a = 0b10100011;   // Fast PWM & Normal Output
  *tccr1b = 0b00011011;   // Pre-Scaler 64
  *ddrb = 0b00000010;
  
  unsigned int counter = 0;
  long value = 0; 
  Serial.begin(9600);


  for (;;)
  {
    value = ((sin((2*PI/5000*11*counter)) +1) * 128);
    *ocr1al = value;
    Serial.println(value);
    counter++;
    delay(11);    // Sampling period = (1/90.91) = 10.99989 ms which is almost 11 ms
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
}
