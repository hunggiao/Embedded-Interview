#include<stdio.h>

static int a = 0; // static int a;

void test(){
    a = a + 20;
    printf("test: %d\n",a);
}

int main(int argc, char const *argv[])
{
    test(); //20
    a = a + 15;
    printf("main: %d\n",a); //35
    return 0;
}
