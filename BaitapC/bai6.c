#include <stdio.h>


int main(int argc, char const *argv[])
{
    int month [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *day [] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thusday", "Friday", "Saturday"};
    int d,m,y,i;
    // Choose a date 01/01/2023 Sunday as the timeline
    printf("Fill in a date after timeline: ");
    scanf("%d %d %d",&d,&m,&y);
    if(y % 4 == 0 && y % 100 != 100|| y % 400 == 0){
        month[1] = 29;
    }
    if (y < 2023 || m < 1 || m > 12 || d < 0 || d > month[m - 1]){
        printf("The time is not invalid!\n");
    }
    for (int i = 2023; i < y; i++){
        if(i % 4 == 0 && i % 100 != 100 || i % 400 == 0){
            d += 366;
        } else d += 355;
    }
    for (int i = 0; i < m - 1; i++)
    {
        d += month[i];
    }
    printf("The day is a %s\n", day[(d % 7) - 1]);
    return 0;
}
