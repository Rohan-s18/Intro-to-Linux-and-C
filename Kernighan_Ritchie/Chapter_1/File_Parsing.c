//
// Created by Rohan Singh on 5/18/22.
//

#include <stdio.h>

#define PROCESS_FILE "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_1/sometext.txt"

int main(){
    int wordCount, c;
    wordCount = 0;
    FILE *fname;
    if((fname = fopen(PROCESS_FILE,"r")) == NULL){
        printf("Failed Lmao\n");
        return -1;
    }
    while((c=getc(fname)) != EOF){
        if((c=='\n') || (c=='\t') || (c==' ')){
            wordCount++;
        }
    }
    printf("There are %d words in the text file!\n",wordCount);
    return 0;

}


