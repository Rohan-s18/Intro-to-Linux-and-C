//
// Created by Rohan Singh on 5/27/22.
//

#include <stdio.h>
#include <strings.h>
#include "calc.h"

#define MAX_LINE 100
//#define dprintf(expr) printf(#expr " = %d\n", expr)

void calculate(){
    char str[MAX_LINE], numStr1[MAX_LINE], numStr2[MAX_LINE];
    while(scanAndCheck(str)!='Q'){
        int num1, num2, operator, result;
        int i, j;
        for(i = 0; i < strlen(str);i++){
            if((str[i]=='+')||(str[i]=='-')||(str[i]=='*')||(str[i]=='/')||(str[i]=='^')){
                operator = str[i];
                numStr1[i] = '\0';
                i++;
                break;
            }
            numStr1[i] = str[i];
        }
        for(j = 0; i < strlen(str);i++,j++)
            numStr2[j] = str[i];
        numStr2[j+1] = '\0';
        num1 = stringToInt(numStr1);
        num2 = stringToInt(numStr2);
        switch (operator) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            case '^':
                result = intPow(num1, num2);
                break;
            default:
                printf("Exiting!\n");
                result = 0;
                return;
        }
        printf("The result of %s is: %d\n",str,result);
    }

}

char scanAndCheck(char str[]){
    scanf("%s",str);
    return str[0];
}