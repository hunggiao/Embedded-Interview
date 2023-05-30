#include<stdio.h>
#include<string.h>

int main(){
    char array[] = {"mot hai ba, bon nam"};
    printf("Chuoi ban dau: %s\n",array);
    int len;
    len=strlen(array);
    printf("Chuoi sau khi dao: ");
    for(int i=len;i>=0;--i){
        if(array[i]==' '){
        printf("%s",array+i+1);
        array[i]='\0';
        printf(" ");
        }
        else if(i==0) printf("%s",array);
    }
return 0;
}

