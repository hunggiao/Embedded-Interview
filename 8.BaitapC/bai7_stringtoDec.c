#include <stdio.h>
#include <stdint.h>

typedef enum{
    NUMBER,
    OPERATOR,
}TypeMath;

typedef struct
{
    TypeMath key;
    union 
    {
        uint16_t number;
        char operator;
    }value;
}TypeMaths;

void stringToDec(char input[], TypeMaths output[]){
    uint16_t number = 0;
    uint8_t i = 0;
    while (*input != '\0')
    {
        if (*input >= '0' && *input <= '9'){
            uint8_t temp = *input - '0';
            number = 10 * number + temp;
            input++;
            continue;
        }else if(*input == '+' || *input == '-' ||
                 *input == '*' || *input == '/'){
                output[i].key = OPERATOR;
                output[i].value.operator = *input;
                i++;
                input++;
                continue;
        }else{
            if(number != 0){
                output[i].key = NUMBER;
                output[i].value.number = number;
                number = 0;
                i++;
            }
        }
        input++;
    }
    output[i].key = NUMBER;
    output[i].value.number = number;
}

int addition(int a, int b){
    return a + b;   
}

int subtraction(int a, int b){
    return a - b;
}

int multiplication(int a, int b){
    return a * b;
}

int division(int a, int b){
    return a/b;
}

int main(int argc, char const *argv[])

{
    char input[] = "10 + 8 - 678 + 6 - 532 - 2";
    TypeMaths output[20];
    stringToDec(input, output);
    for (int i = 0; i < 20; i++)
    {
        if(output[i].key == NUMBER){
            printf("%d",output[i].value.number);
        }else if(output[i].key == OPERATOR){
            printf("%c",output[i].value.operator);
        }else{
            break;
        }
    }
    printf("\n");
    return 0;

}
