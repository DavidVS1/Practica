#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#use standard_io(b)
#use standard_io(a)
#define retardo 500


void error();

void main (void){
   SETUP_ADC_PORTS(NO_ANALOGS);
   setup_oscillator(OSC_32MHZ);
   int16 resultado=0;
   int16 operando1=0,operando2=0;
   while(True){
   operando1=input_c();
   operando2=input_d();
   if(input(PIN_B4) == 1){
   resultado = operando1 + operando2;
      
   }
   if(input(PIN_B5) == 1)
   {
   resultado = operando1 - operando2;
   }
   if(input(PIN_B6) == 1)
   {
   resultado = operando1 * operando2;
   }
   if(input(PIN_B7) == 1)
   {
   if(input_d()==0)
   {
   error();
   }else
   resultado = operando1 / operando2;
   }
   output_a(resultado);
   output_b(resultado>>6);
   output_e(resultado>>10);
   }
   
}   
void error()
{
   int i;
   for(i=0;i<5;i++)
   {
   output_e(0b00000111);
   output_a(0b00111111);
   output_b(0b00001111);
   delay_ms(retardo);
   output_b(0b00000000);
   output_e(0b00000000);
   output_a(0b00000000);
   output_b(0b00000000);
   }
}

