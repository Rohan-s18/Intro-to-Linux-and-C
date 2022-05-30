//
// Created by Rohan Singh on 3/18/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char* str;
    str = malloc(12*sizeof(char));
    printf("Using malloc()\n");
    printf("The address of str is: %p\n\n",&str);

    printf("Using String Copy\n");
    strcpy(str,"Hello World!");
    printf("The address of str is: %p\n",&str);
    printf("The value of str is: %s\n\n",str);

    str = realloc(str,20*sizeof(char ));
    printf("Using realloc()\n");
    printf("The address of str is: %p\n",&str);
    printf("The value of str is: %s\n\n",str);

    printf("Using String Copy\n");
    strcpy(str,"Hello, my name is Snoopy!");
    printf("The address of str is: %p\n",&str);
    printf("The value of str is: %s\n\n",str);

    free(&str);
    printf("Freeing up str\n");
    /*if(str){
        printf("The address of str is: %p\n",&str);
        printf("The value of str is: %s\n",str);
    }*/
    if(!str){
        printf("Str has been freed\n");
    }


    return 0;

}

