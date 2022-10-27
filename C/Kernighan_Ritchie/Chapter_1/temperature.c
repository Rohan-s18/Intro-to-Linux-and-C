//
// Created by rohan on 5/14/22.
//

#include <stdio.h>

#define LOWER_BOUND -100
#define UPPER_BOUND 100
#define STEP_SIZE 10

int main(){
    int fahr, celc;
    celc = LOWER_BOUND;
    printf("%s\t\t%s\n","Celsius","Fahrenheit");
    for(celc; celc <= UPPER_BOUND; celc+=STEP_SIZE){
        fahr = (1.8*celc) + 32;
        printf("%d\t\t\t%d\n",celc,fahr);
    }
    return 0;
}
