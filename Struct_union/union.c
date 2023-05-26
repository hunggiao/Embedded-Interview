#include<stdio.h>
#include<stdint.h>

// union co kich thuoc bang member co kich thuoc lon nhat
// union su dung cung 1 dia chi cho cac bien => bien khai bao sau de len bien truoc 
// union duoc su dung khi chi chon dung 1 bien 
typedef union 
{
    uint64_t a;
    uint8_t b;
    uint32_t c;
}typeData;

void hienthi(typeData data){
    printf("a: %lu, b: %lu, c: %lu\n",data.a, data.b, data.c);
}

int main(int argc, char const *argv[])
{   
    typeData data;
    printf("Dia chi union: %p\n",&data);
    printf("Dia chi a: %p\n",&(data.a));
    printf("Dia chi b: %p\n",&(data.b));
    printf("Dia chi c: %p\n",&(data.c));

    data.a = 12;
    data.b = 27;
    data.c = 35;
    hienthi(data);

    return 0;
}
