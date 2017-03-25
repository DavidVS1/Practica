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
   int1 valError=0;
   int16 operando1=0,operando2=0;
   int8 operacion=0;
   while(True){
   valError=0;
   operando1=input_c();
   operando2=input_d();
   if(input(PIN_B4)==1) operacion=1;
   else if(input(PIN_B5)==1) operacion=2;
   else if(input(PIN_B6)==1) operacion=3;
   else if(input(PIN_B7)==1) operacion=4;
   if(operacion==1){
   resultado = operando1 + operando2;
   }
   else if(operacion == 2)
   {
   resultado = operando1 - operando2;
   }
   else if(operacion == 3)
   {
   resultado = operando1 * operando2;
   }
   else if(operacion == 4)
   {
   if(input_d()==0)
   {
   valError=1;
   error();
   }else
   resultado = operando1 / operando2;
   }
   if(valError==0)
   {
   output_a(resultado);
   output_b(resultado>>6);
   output_e(resultado>>10);
   }
   } 
}   
void error()
{
   int i;
   for(i=0;i<5;i++)
   {
   output_a(0b00111111);
   output_bit( PIN_B0, 1);
   output_bit( PIN_B1, 1);
   output_bit( PIN_B2, 1);
   output_bit( PIN_B3, 1);
   output_bit( PIN_E0, 1);
   output_bit( PIN_E1, 1);
   output_bit( PIN_E2, 1);
   delay_ms(retardo);
   output_a(0b00000000);
   output_bit( PIN_B0, 0);
   output_bit( PIN_B1, 0);
   output_bit( PIN_B2, 0);
   output_bit( PIN_B3, 0);
   output_bit( PIN_E0, 0);
   output_bit( PIN_E1, 0);
   output_bit( PIN_E2, 0);
   delay_ms(retardo);
   }
}

