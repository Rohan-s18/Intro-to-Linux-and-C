#include <stdio.h>
#include <math.h>
 
 int main(){
    int decimalNum;
    int binaryDigits[] = {1,0,1,1,1,0,0,1};
    char binaryChars[] = {'1','0','1','1','1','0','0','1'};
    printf("8-bit binary number:");
    printf(binaryChars);
    printf("\n");
    int validNum = 1;
    for(int i = 0; i < 8; i++){
        if(binaryDigits[i] != 0 && binaryDigits[i] != 1){
            printf("You have entered an invalid number");
            validNum = 0;
        }
    }
    if(validNum == 1){
        for(int j = 0; j < 8; j++){
            int tempu = (int)(pow(2, j)+1e-9);
            tempu++;
            int temp = binaryDigits[j] * tempu;
            decimalNum = decimalNum + temp;
        }
        printf("The Decimal Equivalent is: %d",decimalNum);  
    }
      


    return 0;
 }