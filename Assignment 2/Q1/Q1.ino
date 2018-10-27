unsigned char* ddrb = (unsigned char*) 0x24;    //Points to DDRB
unsigned char* portb = (unsigned char*) 0x25;   //Points to PORTB

unsigned char* ddrc = (unsigned char*) 0x27;    //Points to DDRC
unsigned char* portc = (unsigned char*) 0x28;   //Points to PORTC

unsigned char* ddrd = (unsigned char*) 0x2A;    //Points to DDRD
unsigned char* portd = (unsigned char*) 0x2B;   //Points to PORTD


class Blinky
{
    // Class Member Variables
    // These are initialized at startup

    char PortSymbol; // the port name
    int ledPin;      // the number of the LED pin
    long OnTime;     // milliseconds of on-time
    long OffTime;    // milliseconds of off-time

    // These maintain the current state
    int ledState;                        // ledState used to set the LED
    unsigned long previousMillis = 0;    // will store last time LED was updated

    // Constructor - creates a Blink
    // and initializes the member variables and state

public:

    Blinky(char port, int pin, long on, long off)
    {
        PortSymbol = port;
        ledPin = pin;

        OnTime = on;
        OffTime = off;

        ledState = 0;
        previousMillis = 0;
    }

    void Update(unsigned char* port)
    {
        if (!ledState && (millis() - previousMillis >= OffTime))
        {
            ledState = 1;         
            *port |= (1 << ledPin);  
            previousMillis = millis();    
        }

        else if (ledState && (millis() - previousMillis >= OnTime))
        {
            ledState = 0;
            *port &= ~(1 << ledPin);  
            previousMillis = millis();    
        }
    }

    void Register()
    {
        switch(PortSymbol)
        {
            case 'b':
            case 'B':
                *ddrb |= (1 << ledPin);
                Update((unsigned char *) 0x25);
                break;

            case 'c':
            case 'C':
                *ddrc |= (1 << ledPin);
                Update((unsigned char *) 0x28);
                break;

            case 'd':
            case 'D':
                *ddrd |= (1 << ledPin);
                Update((unsigned char *) 0x2B);
                break;

            default:
                break;
        }
    }
};


void setup()
{
    Blinky led1('D',0,750,350);
    Blinky led2('D',1,400,600);
    
    for (;;)
    {
        led1.Register();
        led2.Register();
    }
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
