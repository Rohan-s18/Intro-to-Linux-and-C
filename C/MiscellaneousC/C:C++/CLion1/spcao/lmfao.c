//
// Created by Rohan Singh on 2/20/22.
//

#include <stdio.h>
#include <stdlib.h>

struct Chat{
    char message1[35];
    char message2[35];
};

void askOut();

int main(){
    askOut();
    return 0;
}

void askOut(){
    char str[35];
    fprintf(stderr,"Hello Rohan!\n");
    scanf("%s",&str);
    fprintf(stderr,"\n");
    struct Chat chat  = {"What do you want to tell me?","I love you too Rohan!"};
    fprintf(stderr,chat.message1);
    fprintf(stderr,"\n\n");
    scanf("%s",&str);
    fprintf(stderr,chat.message2);
    fprintf(stderr,"\n\n");
}





