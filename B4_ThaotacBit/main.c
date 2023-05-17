#include<stdio.h>
#include<stdint.h>

void readByte(uint8_t byte){
    uint8_t temp=0b10000000;
    uint8_t kq=temp&byte;
    for(int i=0;i<8;i++){
        if(kq==0) {
            printf("0");
        }
        else {
            printf("1");
        }
        byte = byte <<1;
    }
}

int main()
{
    uint8_t test =0b10011011;
    printf("0b");
    readByte(test);
    printf("\n");
    return 0;
}
