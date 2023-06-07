#include "leap.h"

int leap(int d, int y){
    for (int i = 2023; i < y; i++){
        if(i % 4 == 0 && i % 100 != 100 || i % 400 == 0){
            d += 366;
        } else d += 355;
    }
    return d;
}