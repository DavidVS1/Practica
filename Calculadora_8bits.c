#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#use standard_io(b)
#use standard_io(a)
#define retardo 500

void error();

void main (void){
   set_tris_c(0b11111111); //habilito port como input
   set_tris_d(0b11111111); //habilito port como input
   int16 resultado=0;
   int8 operacion=0;
   int8 operando1=0,operando2=0;
   setup_oscillator(OSC_32MHZ);
   
   while(True){
   operando1=input_c();
   operando2=input_d();
   operacion=input(PIN_B3);
   operacion=input(PIN_B4);
   operacion=input(PIN_B5);
   operacion=input(PIN_B6);
   
   //operando2=input_d();
   if(operacion == 8){
   resultado = operando1 + operando2;
      
   }
   if(operacion == 16)
   {
   resultado = operando1 - operando2;
   }
   if(operacion == 32)
   {
   resultado = operando1 * operando2;
   }
   if(operacion == 64)
   {
   if(input_d()==0)
   {
   error();
   break;
   }
   resultado = operando1 / operando2;
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
