#include <stdio.h>
#include<string.h>


int main(int argc, char const *argv[])
{
    char *array = "Hello"; //text
    char array1[] = "Hello"; //stack
    char *array2[] = { "Hi", "Hello", "world"}; //pointer to pointer
    printf("test: %s\n", *array2); //Hi
    printf("test: %c\n", *(*(array2+1)+1));//e

    /*int a = 27;
    int *ptr = &a;
    int **ptr = & ptr;
    printf("%d\n",**ptr);*/
    return 0;
}
