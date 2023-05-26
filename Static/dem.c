#include<stdio.h>

int count=16;

void dem(){
    static int a=10;
    printf("a=%d",a);
    count++;
}