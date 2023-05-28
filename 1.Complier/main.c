#include <stdio.h>
#include "test.c"

#define MAX 10

int main(int argc, char const *argv[])
{
    hienthi();
    printf("MAX = %d\n",MAX);
    return 0;
}
 // Tao file main.i: gcc -E main.c -o main.i
 // Tao file main.s: gcc main.i -s -o main.s
 // Tao file main.o: gcc -c main.s -o main.o
 /* Tao file main.exe: g++ -c <diachifile>/main.c
                       g++ -o main.exe main.c */
 // Chay file main.exe: .\main.exe