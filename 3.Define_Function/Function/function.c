#include <stdio.h>

int sum(int a, int b){
    return a+b;
}


int main(int argc, char const *argv[])
{

    printf("Tong a va b: %d\n",sum(5,6));

    printf("Tong a va b: %d\n",sum(3,7));

    return 0;
}
