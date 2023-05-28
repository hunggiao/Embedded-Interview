#include<stdio.h>
#include<stdint.h>

uint8_t PORTA=0b10101100;
//uint8_t PORTB=0b11111111;
void readByte(uint8_t byte){
    uint8_t temp = 0b10000000;
    printf("0b");
    for(int i=0;i<8;i++){
        uint8_t kq = temp & byte;
        if(kq==0) {
            printf("0");
        }
        else {
            printf("1");
        }
        byte <<= 1;
    }
    printf("\n");
}

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} s_pins;

typedef enum{
    LOW,
    HIGH
}s_status;

/*void pinHigh(s_pins pin){
    PORTA = PORTA |(0b10000000 >> pin);
}

void pinLow(s_pins pin){
    PORTB = PORTB & ~(0b10000000 >> pin);
}*/
void digitalWrite(s_pins pin, s_status status){
    if(status==1){
       PORTA = PORTA |(0b10000000 >> pin); 
    }
    else {
        PORTA = PORTA & ~(0b10000000 >> pin);
    }
}
int main()
{
    /*pinHigh(PIN3);
    readByte(PORTA);
    pinLow(PIN6);
    readByte(PORTB);*/
    digitalWrite(PIN4,LOW);//0b10100100
    digitalWrite(PIN5,LOW);//0b10100000
    digitalWrite(PIN7,HIGH);//0b10100001
    digitalWrite(PIN6,HIGH);//0b10100011
    readByte(PORTA);
    return 0;
}
