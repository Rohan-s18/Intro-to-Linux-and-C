//
// Created by Rohan Singh on 5/25/22.
//
#include <stdio.h>
#include <strings.h>
void itos(int x, char str[]);
void reverseStr(char str[]);
int main(){
    int x = -12345;
    int y = 98760;
    char xStr[7];
    char yStr[6];
    itos(x,xStr);
    itos(y,yStr);
    printf("The int is %d and its string is: %s\n",x,xStr);
    printf("The int is %d and its string is: %s\n",y,yStr);
    return 1;
}
void itos(int x, char str[]){
    int index = 0;
    int sign;
    if((sign = x) < 0) x = -x;
    do str[index++] = x%10 + '0';
    while((x/=10) > 0);
    if(sign < 0) str[index++] = '-';
    str[index] = '\0';
    reverseStr(str);

}
void reverseStr(char str[]){
    int i, j;
    char c;
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--){
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}
