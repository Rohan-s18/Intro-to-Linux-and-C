//
// Created by Rohan Singh on 5/25/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int stoi(char str[]);
int power(int a, int b);
int main(){
    char *str1, *str2;
    str1 = malloc(7*sizeof(char));
    str2 = malloc(6*sizeof(char));
    strcpy(str1,"-12345");
    strcpy(str2,"98760");
    printf("The string is: %s and its int is: %d\n",str1, stoi(str1));
    printf("The string is: %s and its int is: %d\n",str2, stoi(str2));
    return 0;
}
int stoi(char str[]){
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
        temp *= power(10,digit);
        x += temp;
        digit--;
    }
    if(sign == '-') x *= -1;
    return x;
}
int power(int a, int b){
    if(b==0) return 1;
    return a*power(a,b-1);
}

