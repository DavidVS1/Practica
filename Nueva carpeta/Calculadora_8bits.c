#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)
#use standard_io(b)
#use fixed_io(a_outputs=PIN_A0, PIN_A1)
#use standard_io(a)
#define retardo 500


void error();

void main (void){
   set_tris_c(0b11111111); //habilito port como input
   set_tris_d(0b11111111); //habilito port como input
   int16 resultado=0;
   SETUP_ADC_PORTS(NO_ANALOGS);
   int8 operacion=0;
   int8 operando1=0,operando2=0;
   setup_oscillator(OSC_32MHZ);
   while(True){
   error();
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
   if(input(PIN_B4) == 1)
   {
   resultado = operando1 - operando2;
   }
   if(input(PIN_B5) == 1)
   {
   resultado = operando1 * operando2;
   }
   if(input(PIN_B6) == 1)
   {
   if(input_d()==0)
   {
   error();
   break;
   }
   resultado = operando1 / operando2;
   }
   operando1=0;
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

