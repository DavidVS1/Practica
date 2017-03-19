#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#use standard_io(b)
#define retardo 500

void error();

void main (void){
   int16 resultado=0;
   int8 operando1=0,operando2=0;
   setup_oscillator(OSC_32MHZ);
   
   while(True){
   if(input(PIN_B3) == 1){
   resultado = operando1 + operando2;
      
   }
   if(input(PIN_B4) == 1)
   {
   resultado = operando1 - operando2;
   }
   if(input(PIN_B3) == 1)
   {
   resultado = operando1 * operando2;
   }
   if(input(PIN_B3) == 1)
   {
   if(input_d()==0)
   error();
   }
   }
}   
void error()
{
   int i;
   for(i=0;i<5;i++)
   {
   output_b(0b00000001);
   delay_ms(retardo);
   output_b(0b00000000);
   }
}
