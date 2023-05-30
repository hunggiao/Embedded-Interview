// Sap xep mang tang dan: array[] = {1,3,5,2,3,4,5,6,2,6,9,6,7}
// So lan xuat hien cac so trong mang
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
    printf("\n");
}


int main(int argc, char const *argv[])
{
    uint8_t array[]={1,3,5,2,3,4,5,6,2,6,9,6,7};
    int n = sizeof(array);
    printf("Mang da sap xep: ");
    sortList(n,array);
    for (int i = 0; i < n; i++)
    {
        int dem=1;
        if (i>0 && array[i]==array[i-1]) continue;
        {
            for (int j = i+1; j <n ; j++)
            {
                if (array[i]==array[j])
                {       
                    dem++;
                }
            }
           printf("So %d xuat hien %d lan\n",array[i],dem); 
        }
        
    }
    
    return 0;
}
