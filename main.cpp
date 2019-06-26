#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX);

AnalogIn tanque(p20);

Serial blue(p9, p10); // TX, RX

DigitalOut myled(LED1);
DigitalOut myled4(LED4);

//DigitalOut MotorR[2] = {p21, p22}; 
//DigitallOut MotorL[2] = {p23,p24};

PwmOut MotorR0 = p21;
PwmOut MotorR1 = p22;
PwmOut MotorL0 = p23;
PwmOut MotorL1 = p24;


DigitalOut Bomba[2] = {p25,p26};

void AtualizaBomba(){
        if(Bomba[0]==0)
            Bomba[0]=1;
        else
            Bomba[0]=0;
        Bomba[1]=1;
    }

void RodaMotorPwm(PwmOut motor0, PwmOut motor1, int girar){
        
        int vel = .7f;
        int parar = 1;
        switch(girar){
        case(1):
            motor0 = parar;
            motor1 = vel;
            break;
        case(0):
            motor0 = parar;
            motor1 = parar;
            break;
        case(-1):
            motor0 = vel;
            motor1 = parar;
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
                    blue.puts("Esquerda");
                    //RodaMotor(MotorR, -1);
                    //RodaMotor(MotorL, 1);
                    RodaMotorPwm(MotorR0,MotorR1,-1);
                    RodaMotorPwm(MotorL0,MotorL1,1);
                    break;
                
                case 't':
                    blue.puts("Frente");
                    //RodaMotor(MotorR, -1);
                    //RodaMotor(MotorL, -1);
                    RodaMotorPwm(MotorR0,MotorR1,-1);
                    RodaMotorPwm(MotorL0,MotorL1,-1);
                    break;
                
                case 'r':
                    blue.puts("Direita");
                    //RodaMotor(MotorR, 1);
                    //RodaMotor(MotorL, -1);
                    RodaMotorPwm(MotorR0,MotorR1,1);
                    RodaMotorPwm(MotorL0,MotorL1,-1);
                    break;
                
                case 'b':
                    blue.puts("Tras");
                    //RodaMotor(MotorR, 1);
                    //RodaMotor(MotorL, 1);
                    RodaMotorPwm(MotorR0,MotorR1,1);
                    RodaMotorPwm(MotorL0,MotorL1,1);
                    break;

                case 'p':
                    blue.puts("Para");
                    //RodaMotor(MotorR, 0);
                    //RodaMotor(MotorL, 0);
                    RodaMotorPwm(MotorR0,MotorR1,0);
                    RodaMotorPwm(MotorL0,MotorL1,0);
                    
                    break;

                case 'w':
                    blue.puts("Agua");
                    AtualizaBomba();
                    break;
            }
            myled = !myled;
        }
        if (pc.readable()) //RECEBE DA PLACA
        {

            myled4 = !myled4;
        }
    }
}#include "mbed.h"
#include <string>

Serial pc(USBTX, USBRX);

AnalogIn tanque(p20);

Serial blue(p9, p10); // TX, RX

DigitalOut myled(LED1);
DigitalOut myled4(LED4);

PwmOut MotorR0 = p21;
PwmOut MotorR1 = p22;
PwmOut MotorL0 = p23;
PwmOut MotorL1 = p24;


DigitalOut Bomba[2] = {p25,p26};

void AtualizaBomba(){
        if(Bomba[0]==0)
            Bomba[0]=1;
        else
            Bomba[0]=0;
        Bomba[1]=1;
    }

void RodaMotorPwm(PwmOut motor0, PwmOut motor1, int girar){
        
        int vel = .7f;
        int parar = 1;
        switch(girar){
        case(1):
            motor0 = parar;
            motor1 = vel;
            break;
        case(0):
            motor0 = parar;
            motor1 = parar;
            break;
        case(-1):
            motor0 = vel;
            motor1 = parar;
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
                    blue.puts("Esquerda");
                    //RodaMotor(MotorR, -1);
                    //RodaMotor(MotorL, 1);
                    RodaMotorPwm(MotorR0,MotorR1,-1);
                    RodaMotorPwm(MotorL0,MotorL1,1);
                    break;
                
                case 't':
                    blue.puts("Frente");
                    //RodaMotor(MotorR, -1);
                    //RodaMotor(MotorL, -1);
                    RodaMotorPwm(MotorR0,MotorR1,-1);
                    RodaMotorPwm(MotorL0,MotorL1,-1);
                    break;
                
                case 'r':
                    blue.puts("Direita");
                    //RodaMotor(MotorR, 1);
                    //RodaMotor(MotorL, -1);
                    RodaMotorPwm(MotorR0,MotorR1,1);
                    RodaMotorPwm(MotorL0,MotorL1,-1);
                    break;
                
                case 'b':
                    blue.puts("Tras");
                    //RodaMotor(MotorR, 1);
                    //RodaMotor(MotorL, 1);
                    RodaMotorPwm(MotorR0,MotorR1,1);
                    RodaMotorPwm(MotorL0,MotorL1,1);
                    break;

                case 'p':
                    blue.puts("Para");
                    //RodaMotor(MotorR, 0);
                    //RodaMotor(MotorL, 0);
                    RodaMotorPwm(MotorR0,MotorR1,0);
                    RodaMotorPwm(MotorL0,MotorL1,0);
                    
                    break;

                case 'w':
                    blue.puts("Agua");
                    AtualizaBomba();
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