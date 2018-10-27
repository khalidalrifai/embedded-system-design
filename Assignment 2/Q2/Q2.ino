unsigned char* pinb = (unsigned char*) 0x23;
unsigned char* ddrb = (unsigned char*) 0x24;
unsigned char* portb = (unsigned char*) 0x25;

unsigned char* pinc = (unsigned char*) 0x26; 
unsigned char* ddrc = (unsigned char*) 0x27;
unsigned char* portc = (unsigned char*) 0x28;

unsigned char* pind = (unsigned char*) 0x19;
unsigned char* ddrd = (unsigned char*) 0x2A;
unsigned char* portd = (unsigned char*) 0x2B;

unsigned int A_count = 0;
unsigned int B_count = 0;
unsigned int C_count = 0;
unsigned int D_count = 0;
unsigned int E_count = 0;


class Button
{
  private:
    char port;
    short int pinNumber;
    unsigned long debouncingPeriod;
    bool state;
    bool pullUp;
    bool current = 0;
    bool previous = 0;
    unsigned long pressedTime = 0;
    void switching();
        
  public:
    Button(char, short int, unsigned long, bool, bool);
    void Refresh(void);
    void (*pressed)(void);
};


Button::Button(char _port, short int _pinNumber, unsigned long _debouncingPeriod, bool _pullUp, bool _state)
{
  port = _port;
  pinNumber = _pinNumber;
  debouncingPeriod = _debouncingPeriod;
  pullUp = _pullUp;
  state = _state;
  switching();
}

void Button::switching()
{
  switch(port)
  {
    case 'd':
    case 'D':
      *ddrd &= ~(1 << pinNumber);
      *portd |= (pullUp << pinNumber);
      break;
      
    case 'b':
    case 'B':
      *ddrb &= ~(1 << pinNumber);
      *portb |= (pullUp << pinNumber); 
      break;

    case 'c':
    case 'C':
      *ddrc &= ~(1 << pinNumber);
      *portc |= (pullUp << pinNumber); 
      break;
  }
}

void Button::Refresh()
{
  if(port == 'B' || port == 'b')
  {
    current = (*pinb & (1 << pinNumber));
    if(current & !previous)
    {
      if((millis() - pressedTime) >= debouncingPeriod)
      {
        pressed();
      }
    
    pressedTime = millis();
    }
    
    previous = current;
  }
  
  else if(port == 'C' || port == 'c')
  {
    current = (*pinc & (1 << pinNumber));
    if(current & !previous)
    {
      if((millis() - pressedTime) >= debouncingPeriod)
      {
        pressed();
      }
    
    pressedTime = millis();
    }
    
    previous = current;
  }
  
  else if(port == 'D' || port == 'd')
  {
    current = (*pind & (1 << pinNumber));
    if(current & !previous)
    {
      if((millis() - pressedTime) >= debouncingPeriod)
      {
        pressed();
      }
    
    pressedTime = millis();
    }
    
    previous = current;
  }
  
}

Button A('B', 2, 20, 1, 1), B('B', 3, 20, 1, 1), C('B', 4, 20, 1, 1), D('C', 4, 20, 1, 1), E('C', 5, 20, 1, 1);
  
void setup()
{
    Serial.begin(9600);
    print();

    A.pressed = A_gets_pressed;
    B.pressed = B_gets_pressed;
    C.pressed = C_gets_pressed;
    D.pressed = D_gets_pressed;
    E.pressed = E_gets_pressed;
    
    while(1)
    {
        A.Refresh();
        B.Refresh();
        C.Refresh();
        D.Refresh();
        E.Refresh();
    }
}


void print(void)
{
    Serial.print("A = ");
    Serial.print(A_count);
  
    Serial.print("  B = ");
    Serial.print(B_count);
  
    Serial.print("  C = ");
    Serial.print(C_count);
  
    Serial.print("  D = ");
    Serial.print(D_count);
  
    Serial.print("  E = ");
    Serial.println(E_count);
}


void A_gets_pressed(void)
{
    A_count++;
    print();
}


void B_gets_pressed(void)
{
    B_count++;
    print();
}


void C_gets_pressed(void)
{
    C_count++;
    print();
}


void D_gets_pressed(void)
{
    D_count++;
    print();
}


void E_gets_pressed(void)
{
    E_count++;
    print();
}
