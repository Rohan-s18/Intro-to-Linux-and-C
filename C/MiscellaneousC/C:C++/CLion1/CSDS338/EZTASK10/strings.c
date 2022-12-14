//
// Created by Rohan Singh on 4/15/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

static const char temp[15];


int main(){
    char tag[32];
    char* cp;
    cp = malloc(sizeof(char)*12);
    char* newLine;
    newLine = malloc(sizeof(char)*30000);
    strcpy(newLine,"oyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoyeoye");
    size_t glug = cp - temp;
    strcpy(temp+glug,newLine);
    printf("%d\n",sizeof(temp));
    printf("%s\n%s\n",newLine,cp);

    /*strcpy(tag,"<...>");
    fprintf(stdout,"%s\n",tag);*/
    return 0;

}

