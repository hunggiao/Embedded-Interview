#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

//stack
void test(){
    char arr[3];

    printf("Dia chi arr: %p\n",arr);
}

//heap
void test2(){
    char *arr = (char*)malloc(sizeof(char)*3);
    printf("Dia chi arr: %p\n",arr);
    free(arr);
}

int main(int argc, char const *argv[])
{

    test();

    test();

    test2();

    test2();

    return 0;
}
