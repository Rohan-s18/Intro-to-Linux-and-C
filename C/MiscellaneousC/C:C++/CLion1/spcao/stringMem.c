//
// Created by Rohan Singh on 2/28/22.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *mystring;
    mystring = malloc(10*sizeof(char ));
    fprintf(stderr,"%s\n",&mystring);
    strcpy(mystring,"Hello World");
    fprintf(stderr,"%s\n",&mystring);

}