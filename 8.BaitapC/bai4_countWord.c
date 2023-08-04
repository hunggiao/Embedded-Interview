// cho 1 chuoi ngau nhien vd: char arr[] = {mot hai mot hai mot mot, ba bon ba}
// dem xem 1 tu xuat hien bao nhieu lan

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100

char words[MAX][50];
int count[MAX] = {0};
int wordCount = 0;
int lenght = 0;

int isEqual(const char arr1[], const char arr2[]){
  int i = 0;
  while (arr1[i] != '\0' && arr2[i] != '\0'){
    if(arr1[i] != arr2[i]){
      return 0;
    }
    i++;
  }
  return arr1[i] == '\0' && arr2[i] == '\0';
}

void splitword(const char str[]){
  int i = 0;
  while (str[i] != '\0'){
    if (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '?' && str[i] != '!') {
        words[wordCount][lenght] = str[i];
        lenght++;
        }else{
            if(lenght > 0){
                words[wordCount][lenght] = '\0';
                wordCount++;
                lenght = 0;
            }
        }
        i++;
  }
        if (lenght > 0) {
        words[wordCount][lenght] = '\0';
        wordCount++;
    }
}

void countword(){

    for (int i = 0; i < wordCount; i++) {
        if (count[i] == -1) {
            continue;
        }

        count[i] = 1;

        for (int j = i + 1; j < wordCount; j++) {
            if (count[j] != -1 && isEqual(words[i], words[j])) {

                count[i]++; // Tăng số lần xuất hiện của từ
                count[j] = -1; // Đánh dấu từ này đã được đếm
            }
        }
    }
}

void printword(){
    for (int i = 0; i < wordCount; i++) {
        if (count[i] != -1) {
            printf("Tu '%s' xuat hien %d lan\n", words[i], count[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
  char array[] = {"mot hai mot hai mot mot, ba bon ba"};
  splitword(array);
  countword();
  printword();
  return 0;
}


  
