//
// Created by Rohan Singh on 3/2/22.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    char *mypointer;
    char *earlystuff;
    char *goodstuff;
    earlystuff = malloc(1000*sizeof(char));
    for (int i=0; i<1000; i+=1) *(earlystuff+i) = 'c';
    for (int i=2; i<1000; i+=6) *(earlystuff+i) = 'w';
    for (int i=3; i<1000; i+=6) *(earlystuff+i) = 'r';
    for (int i=4; i<1000; i+=6) *(earlystuff+i) = 'u';
    *(earlystuff+999) = '\0';
    goodstuff = malloc(1000*sizeof(char));
    for (int i=0; i<1000; i++) *(goodstuff+i) = 'h';
    for (int i=0; i<1000; i+=2) *(goodstuff+i) = 'e';
    for (int i=0; i<1000; i+=3) *(goodstuff+i) = 'l';
    for (int i=0; i<1000; i+=4) *(goodstuff+i) = 'l';
    for (int i=0; i<1000; i+=5) *(goodstuff+i) = 'o';
    *(goodstuff+999) = '\0';

    printf("\n\nLmao\n\n");

    printf("%d\n",(int) '\0');
    printf("earlystuff@%p = %s\n", earlystuff, earlystuff);
    printf("goodstuff@%p = %s\n", goodstuff, goodstuff);
    printf("just more output\n");

    for (int i=1; i<=2000; i++) {
        printf("just some output %d\n",i);
        mypointer = goodstuff+999+i;
        printf("\n\n%p+%d, %p, %s\n", goodstuff, 999+i, mypointer, mypointer);
        mypointer = goodstuff-i;
        printf("\n\n%p-%d, %p, %s\n", goodstuff, i, mypointer, mypointer);
    }
}

