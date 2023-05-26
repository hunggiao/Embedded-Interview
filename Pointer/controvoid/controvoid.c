#include<stdio.h>

void tong (int a, int b){
    printf("tong %d va %d = %d\n",a,b,a+b);
}

int main(int argc, char const *argv[])
{   
    int i = 10;

    double d = 15.6;

    char c = 'B';

    //Con tro void co the tro den moi dia chi nhung khong lay gia tri duoc
    //Ep kieu cho con tro void -> in duoc gia tri

    void *ptr = &i;

    printf("i = %d\n",*(int*)ptr);

    ptr = &d;

    printf("d = %lf\n",*(double*)ptr);

    ptr = &c;

    printf("c = %c\n",*(char*)ptr);

    ptr = &tong;

    ((void (*) (int, int)) ptr)(9,16);//tong 9 va 16 = 25

    return 0;
}
