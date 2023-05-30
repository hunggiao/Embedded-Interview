// Sap xep mang tang dan: array[] = {1,3,5,2,3,4,5,6,2,6,9,6,7}

#include<stdio.h>
#include<stdint.h>

void sortList(uint8_t n, uint8_t array[]){
    uint8_t tmp=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1 ; j < n  ; j++)
        {
            if(array[i]>array[j]) {
                tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
       printf("%d ",array[i]);
    }
}

int main(int argc, char const *argv[])
{
    uint8_t array[]={1,3,5,2,3,4,5,6,2,6,9,6,7};
    int n = sizeof(array);
    sortList(n,array);
    return 0;
}
