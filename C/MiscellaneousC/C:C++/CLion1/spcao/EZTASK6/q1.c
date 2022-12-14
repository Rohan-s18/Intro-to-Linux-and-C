//
// Created by Rohan Singh on 3/2/22.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *mystring;
    mystring = malloc(10*sizeof(char ));
    //fprintf(stderr,"%s\n",&mystring);
    strcpy(mystring,"Hello World");
    fprintf(stderr,"%s\n",mystring);
    for(int i = 1; i < 12; i++){
        printf("%s\n",mystring+i);
    }

}