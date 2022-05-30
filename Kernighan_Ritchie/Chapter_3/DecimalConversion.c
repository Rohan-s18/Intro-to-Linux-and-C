//
// Created by Rohan Singh on 5/25/22.
//
#include <stdio.h>
#include <strings.h>
void itob(int n, int b, char str[], int max);
void reverse(char str[]);
int main(){
    int x = 31;
    int y = 251;
    char hexStr1[3], hexStr2[3], biStr1[9], biStr2[9];
    itob(x,2,biStr1,9);
    itob(x,16,hexStr1,3);
    itob(y,2,biStr2,9);
    itob(y,16,hexStr2,3);
    printf("Decimal: %d\n",x);
    printf("\t\tHexadecimal: 0x%s\t\tBinary: B'%s\n\n",hexStr1,biStr1);
    printf("Decimal: %d\n",y);
    printf("\t\tHexadecimal: 0x%s\t\tBinary: B'%s\n\n",hexStr2,biStr2);
    return 0;
}
void itob(int n, int b, char str[], int max){
    int i = 0;
    do{
        if(i>=max-1){
            printf("Incorrect buffer size!\n");
            return;
        }
        int temp = n%b;
        if(temp > 9)
            temp += 'A' - 10;
        else
            temp += '0';
        str[i++] = temp;
    } while (((n/=b)>0));
    while(i < max-1)
        str[i++] = '0';
    str[i] = '\0';
    reverse(str);
}
void reverse(char str[]){
    int i, j, temp;
    for(i = 0, j = strlen(str) - 1; i < j; i++,j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

