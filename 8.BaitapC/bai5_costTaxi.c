#include<stdio.h>


int main(int argc, char const *argv[])
{
    float len;
    float cost = 0;
    printf("Nhap quang duong da di: ");
    scanf("%d",&len);
    if(len > 0 && len <= 1) {
        cost = len*14000;
    } else if(len > 1 && len <= 30) {
        cost = (len-1)*10000 + 14000;
    } else {
        cost = cost + (len-30)*8000 + 29*10000 + 14000;
    }
    printf("Gia cuoc di taxi la: %f nghin dong\n",cost);
    return 0;
}






