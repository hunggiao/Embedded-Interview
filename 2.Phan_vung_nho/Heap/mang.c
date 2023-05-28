#include<stdio.h>
#include<stdint.h>

uint8_t arr[] = {1, 2, 4, 7, 8};
                //0x01 0x02 0x03 0x04 0x05 


int main(int argc, char const *argv[])
{
    printf("Dia chi 1: %p, gia tri %d\n",arr,*arr);

    printf("Dia chi 2: %p, gia tri %d\n",arr+1,*(arr+1));

    printf("Dia chi 3: %p, gia tri %d\n",arr+2,*(arr+2));
    
    return 0;
}
