//
// Created by Rohan Singh on 3/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char *mypointer;
    char *yourpointer;
    mypointer = malloc(5*sizeof(char));
    yourpointer = malloc(5*sizeof(char));
    strcpy(mypointer,"goodbye world i knew you well");

    for (int i=0; i<20; i++) {
        printf("%d %p %s\n", i, mypointer+i, mypointer+i);
    }
    printf("\nyour: %p %s\n", yourpointer, yourpointer);
}
