#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX);

AnalogIn tanque(p20);

Serial blue(p9, p10); // TX, RX

DigitalOut myled(LED1);
DigitalOut myled4(LED4);

DigitalOut MotorL[2] = {p21, p22};
DigitalOut MotorR[2] = {p23,p24};

void RodaMotor(DigitalOut motor[], int girar){
    switch(girar){
        case(1):
            motor[0] = 1;
            motor[1] = 0;
            break;
        case(0):
            motor[0] = 1;
            motor[1] = 1;
            break;
        case(-1):
            motor[0] = 0;
            motor[1] = 1;
            break;
    }    
    
}

void PrintNivel(){
        float nivel = abs(tanque.read()*100. - 100)*2.7;
        nivel > 98 ? nivel = 100 : nivel = nivel;
        char msg[80];
        sprintf(msg, "%.3f", nivel);
        blue.puts(msg);
        blue.puts("\n");
    }

int main() 
{
    blue.baud(9600);
    pc.baud(9600);
    Ticker ticker;
    pc.printf("BLASTOISE EU ESCOLHO VOCE!\r\n");

    ticker.attach(&PrintNivel, 2);
    
    // echo back characters and toggle the LED
    while (1) 
    {

        
        if (blue.readable())//RECEBE DO CELULAR
        {            
            char comando;
            comando = blue.getc();

            switch (comando)
            {
                case 'l':
                    RodaMotor(MotorR, -1);
                    RodaMotor(MotorL, 1);
                    break;
                
                case 't':
                    RodaMotor(MotorR, -1);
                    RodaMotor(MotorL, -1);
                    break;
                
                case 'r':
                    RodaMotor(MotorR, 1);
                    RodaMotor(MotorL, -1);
                    break;
                
                case 'b':
                    RodaMotor(MotorR, 1);
                    RodaMotor(MotorL, 1);
                    break;

                case 'p':
                    RodaMotor(MotorR, 0);
                    RodaMotor(MotorL, 0);
                    break;

                case 'w':
                    pc.putc(6);
                    break;
            }
            myled = !myled;
        }
        if (pc.readable()) //RECEBE DA PLACA
        {

            myled4 = !myled4;
        }
    }
}
