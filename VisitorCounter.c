#define on 1
#define off 0

sbit RELAY at LATC0_bit;

unsigned int counter;

void init();

void interrupt()
{
   if (INTCON3.INT1IF == 1)
   { //INT1 external interrupt
     counter++;
     if(counter > 0){
        RELAY = on;
     }
     INTCON3.INT1IF = 0; //clear flag
   }
   else if (INTCON3.INT2IF == 1)
   { //INT2 external interrupt
     if(counter >= 0){
        counter--;
     }
     if(counter == 0){
        RELAY = off;
     }
     INTCON3.INT2IF = 0; //clear flag
   }
}

void main()
{
   init();
   while (1);
}

void init(){
   counter = 0;

   TRISB=0b00000110;
   PORTB=0b00000000;

   TRISC0_bit=0;
   RELAY = off;

   ADCON1 = 0b00000111;

   INTCON.GIEH = 1; //enable all high-priority interrupts
   INTCON.GIEL = 1; //enable all low-priority interrupts

   INTCON3.INT1IE = 1; //enable INT1 external interrupt
   INTCON3.INT2IE = 1; //enable INT2 external interrupt
}