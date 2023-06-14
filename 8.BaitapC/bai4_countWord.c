// cho 1 chuoi ngau nhien vd: char arr[] = {mot hai mot hai mot mot, ba bon ba}
// dem xem 1 tu xuat hien bao nhieu lan

#include <stdio.h>
#include <string.h>
#include <math.h>

int length (char array[]){
    int i = 0;
    while (array[i]!='\0'){
        i++;
    }
    return i;
}

char *splitWords(char *string, const char *delim) {

  /* Biến tĩnh được sử dụng để giữ theo dõi chỉ mục của chuỗi trong mỗi lệnh gọi hàm */
  static char * index;

  // Trường hợp ban đầu, nơi người dùng chuyển chuỗi thực trong splitWords
  if (string != NULL) {
    index = string;
  } else {
  // các trường hợp khác, trong đó NULL được thông qua
    string = index;
  }

  // Trường hợp cuối cùng là '\ 0'
  if ( *index == '\0') {
    return NULL;
  }

  while ( * index != '\0') {
    // Lặp lại từng dấu phân cách và kiểm tra xem có bất kỳ dấu phân cách nào khớp với ký tự không
    for (int i = 0; delim[i] != '\0'; i++) {
      if ( *index == delim[i]) {

        // không quan tâm đến trường hợp sau khi không có ký tự nào 
        // không có sẵn để in trước dấu phân cách. 
        // Trường hợp này xảy ra khi hai dấu phân cách nằm cạnh nhau.
        if (index == string) {
          index++;
          string++;
        } else {
          *index = '\0';
          break;
        }
      }
    }

    // trả lại index
    if ( *index == '\0') {
      index++;
      return string;
    }

    index++;
  }
  return string;

}


void cpyArray(char *s, char *t){
    int i=0;
    while ((s[i] = t[i]) != '\0') i++;
}


int compareArray(char *s, char *t){
    int i;
    for (i = 0; s[i] == t [i]; i++)
        if (s[i] == '\0') return 0;
    return s[i] - t[i];
}

int main(){
    char c[] = {"mot hai mot hai mot mot, ba bon ba hai mot"};
    char a[10][10];
    int n = 0;
    char *token = splitWords(c, ", ");
    while (token != NULL)
    {
        cpyArray(a[n],token);
        ++n;
        token = splitWords(NULL,", ");
    }
    int b[100] = {0};
    for (int i = 0; i < n; i++)
    {
        if (b[i]==0)    
        {
            int cnt = 1;
            for (int j = i+1; j < n; j++)
            {
               if (compareArray(a[i],a[j])==0)
               {
                ++cnt;
                b[j] = 1;
               }
               
            }
            printf("%s %d\n",a[i],cnt);
        }
        
    }
    
}