#include<stdio.h>
#include<stdint.h>

void readByte(uint8_t byte){
    uint8_t temp=byte & 0b10000000;
    for(int i=0;i<8;i++){
        if(temp==0) {
            printf("0");
        }
        else {
            printf("1");
        }
        temp = temp <<1;
    }
}

int main(int argc, char const *argv[])
{
    uint8_t test;
    printf("Nhap 1 so nhi phan:");
    scanf("%d",test);
    printf("0b");
    uint8_t ham;
    ham = readByte(test);
    printf("In so nhi phan ra man hinh: ",ham);
    return 0;
}
