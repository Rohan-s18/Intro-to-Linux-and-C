//
// Created by Rohan Singh on 5/27/22.
//

#include <strings.h>

int multiply(int a, int b){
    return a*b;
}

int divide(int a, int b){
    return a/b;
}

int add(int a, int b){
    return a+b;
}

int subtract(int a, int b){
    return a-b;
}

int intPow(int a, int b){
    if(b==0) return 1;
    return a*intPow(a,b-1);
}

int stringToInt(char str[]){
    int x, index, digit, temp;
    char sign = str[0];
    if(sign == '-'){
        index = 1;
        digit = strlen(str) - 2;
    } else{
        index = 0;
        digit = strlen(str) - 1;
    }
    x = 0;
    while(digit >= 0){
        temp = str[index++] - '0';
        temp *= intPow(10,digit);
        x += temp;
        digit--;
    }
    if(sign == '-') x *= -1;
    return x;
}
