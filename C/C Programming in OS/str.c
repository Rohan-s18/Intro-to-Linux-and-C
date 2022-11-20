//
// Created by Rohan Singh on 3/17/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *mystring1;
    char *mystring2;
    char *mystring3;

    mystring1 = malloc(sizeof(char));
    mystring2 = malloc(sizeof(char));
    //mystring3 = malloc(sizeof(char));

    for(int i = 0; i < 10; i++){
        *(mystring1+i) = 'a';
        *(mystring2+i) = 'b';
    }

    printf("String 1: %s\n",mystring1);
    printf("String 2: %s\n",mystring2);

    if(mystring1){
        printf("Memory has been allocated to mystring1\n");
        printf("The location of mystring in memory is: %p\n",&mystring1);
        free(mystring1);
        printf("\n");
    }


    if(mystring1){
        printf("%s\n",mystring1);
        printf("The location of mystring in memory is: %p\n",&mystring1);
    }

    return 0;

}

