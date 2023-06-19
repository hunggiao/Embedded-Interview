#include <iostream>
#include <list>

using namespace std;

/* Linked list: Tốc độ đọc chậm hơn, chèn nhanh hơn so với mảng bình thường
typedef struct 
{
    int value;
    node *next;
}node; */

int main(int argc, char const *argv[])
{
    list<int> array;
    array.push_back(1);
    array.push_back(4);
    array.push_back(9);
    array.push_back(15);



    for(auto item : array){
        printf("%d\n",item);
    }

    
    return 0;
}
