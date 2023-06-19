#include <iostream>
#include <vector>

using namespace std;



int main(int argc, char const *argv[])
{
    vector<int> array;
    array.push_back(1);
    array.push_back(4);
    array.push_back(9);
    array.push_back(15);


    /*array.pop_back(); //xóa phần tử cuối cùng
    array.pop_back();*/


    array.insert(array.begin()+2, 27);

    array.erase(array.begin()+2);

    array.assign(8,9); // tạo ra 8 ô nhớ, mỗi ô đều bằng 9


    /*for (int i = 0; i < array.size(); i++)
    {
        printf("%d\n",array[i]);
    }*/

    for(int item : array){
        printf("%d\n",item);
    }
    
    return 0;
}
