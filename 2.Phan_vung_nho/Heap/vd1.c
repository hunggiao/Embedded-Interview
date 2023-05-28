#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>



int main(int argc, char const *argv[])
{

    uint8_t *arr = (uint8_t*)malloc(sizeof(uint8_t)*5);

    for(int i=0;i<5;i++){
        arr[i]=i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("i = %d\n",arr[i]);
    }
    
    arr = (uint8_t*)realloc(arr,sizeof(uint8_t)*7);

    for(int i=0;i<7;i++){
        arr[i]=2*i;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("i = %d\n",arr[i]);
    }

    return 0;
}