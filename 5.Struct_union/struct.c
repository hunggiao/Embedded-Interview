#include<stdio.h>
#include<stdint.h>

typedef struct typeDate{
    uint16_t arr1[7]; // 2*4 + 2 + 2 + 2 + 2 byte bo nho dem = 16 byte
    uint64_t arr3[5]; // 8*5 = 40 byte
    uint8_t arr4[3]; // 1 + 1 + + 1 + 1 byte bo nho dem = 4 byte
    uint32_t arr2[5]; // 4 (tu bo nho dem arr4) + 4*2 + 4*2 = 20 byte
}date;




int main(int argc, char const *argv[])
{
    printf("Size: %lu\n",sizeof(date)); // size: 80
    return 0;
}
