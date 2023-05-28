#include<stdio.h>

static int a = 15;

void test(){
    a = a + 20;
    printf("test: %d\n",a);
}

int main(int argc, char const *argv[])
{
    test(); //35
    a = a + 15;
    printf("main: %d\n",a); //50
    return 0;
}
