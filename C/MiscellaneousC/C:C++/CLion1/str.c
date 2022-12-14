//
// Created by Rohan Singh on 2/20/22.
//'


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Lmao{
    int age;
    char name[35];
    int PIN;
}lmao;

int main(){
    char tempstr [35];
    int age;
    int pin;

    fprintf(stderr,"Enter your First Name: ");
    scanf("%s",&tempstr);
    fprintf(stderr,"Enter your age: ");
    scanf("%d",&age);
    fprintf(stderr,"Enter your PIN: ");
    scanf("%d",&pin);
    strcpy(lmao.name,tempstr);
    lmao.PIN = pin;
    lmao.age = age;
    fprintf(stderr,"\n\n");
    fprintf(stderr,"Your personal details are: \n");
    fprintf(stderr,"Your name is: %s\n",lmao.name);
    fprintf(stderr,"Your age is: %d\n",lmao.age);
    fprintf(stderr,"Your PIN is: %d\n",lmao.PIN);
    return 0;
}



