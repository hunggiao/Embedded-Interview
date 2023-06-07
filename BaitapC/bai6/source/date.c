#include "date.h"

int date(char month[], int d, int m){
    for (int i = 0; i < m - 1; i++)
    {
        d += month[i];
    }
    return d;
}