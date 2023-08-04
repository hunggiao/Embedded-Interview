#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    list<int> array = {1,6,5,7,8,4,2,3};
    list<int>::iterator it;
    for (it = array.begin(); it != array.end(); ++it){
        if(*it = 6){
            array.erase(it);
            break;
        }
    }
    for (it = array.begin(); it != array.end(); ++it){
        cout<<*it<<endl;
    }
    
    return 0;
}
