#include<stdio.h>


void tong (int a, int b){
    printf("tong %d va %d = %d\n",a,b,a+b);
}

void tich(int a, int b){
    printf("tich %d va %d = %d\n",a,b,a*b);
}

//con tro ham lam inputparameter cua 1 ham
void tinhtoan(int a, int b, void (*ptr)(int,int)){
    printf("Chuong trinh toan\n");
    ptr(a,b);
}

int main(int argc, char const *argv[])
{
    //con tro ham
    void (*ptr)(int,int)=NULL;
    ptr =&tong;
    ptr(9,7);//tong 9 va 7 = 16

    int (*ptr_tich)(int,int)=&tich;
    ptr_tich(6,7);//tich 8 va 5 = 42

    //cach khac

    void (*pheptoan)(int a, int b) =NULL;
    pheptoan=&tong;
    pheptoan(8,5);//tong 8 va 5 = 13

    //con tro ham lam inputparameter cua 1 ham
    tinhtoan(8,9,tich);//tich 8 va 9 = 72

    return 0;
}
