#include <stdio.h>

//const int a = 10;

char arr[]="Hello"; //stack

char *arr2="Hello"; //text

int main(int argc, char const *argv[])
{
    /*a = 27;
    printf("%d",a); //error */

    /* arr2[0]='A';
    printf("test: %s\n",arr2); // error */

    arr[0]='A';
    printf("test: %s\n",arr); // test: Aello
    return 0;
}
