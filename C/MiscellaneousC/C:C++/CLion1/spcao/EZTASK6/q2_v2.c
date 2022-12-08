//
// Created by Rohan Singh on 3/2/22.
//

#include <stdio.h>
#include <stdlib.h>
char *mypointer;
void subr() {
    char *myarray;
    myarray = alloca(100*sizeof(char));
    for (int i=0; i<100; i++) *(myarray+i) = 'a';
    for (int i=0; i<100; i+=2) *(myarray+i) = 'b';
    printf("I AM IN SUBR!\n");
    if (rand()%3) subr();
    for (int i=1; i<=2000; i++) {
        mypointer = myarray+999+i;
        printf("\n\n%p+%d, %p, %s\n", myarray, 999+i, mypointer, mypointer);
        mypointer = myarray-i;
        printf("\n\n%p-%d, %p, %s\n", myarray, i, mypointer, mypointer);
    }
}
int main() {
    printf("just some output\n");
    subr();
    printf("just more output\n");
}
