//
// Created by Rohan Singh on 5/18/22.
//

#include <stdio.h>
#define INPUT_FILE "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_1/AdvancedWordStatsText.txt"
#define EXTRACTION_CHAR1 'T'
#define EXTRACTION_CHAR2 't'
#define MAX_WORD_LENGTH 100
#define MAX_ARRAY_LENGTH 100
//#define EXTRACTION_CHARn
void skipWord();
FILE *fname;
int main(){
    if((fname=fopen(INPUT_FILE,"r"))==NULL){printf("Problem in the file path, please double check the Input File path\n");return -1;}
    int c,wordcount,index;
    wordcount=0;
    char wordList[MAX_ARRAY_LENGTH][MAX_WORD_LENGTH];
    while((c=getc(fname))!=EOF){
        if(c!=EXTRACTION_CHAR1&&c!=EXTRACTION_CHAR2){skipWord();continue;}
        index=0;
        while((c!=EOF)&&(c!='\n')&&(c!='\t')&&(c!=' ')){
            wordList[wordcount][index]=c;
            index++;
            c=getc(fname);
        }
        wordList[wordcount][index++]='\0';
        wordcount++;
    }
    printf("There are %d words that start with %c or with %c, these words are:\n",wordcount++,EXTRACTION_CHAR1,EXTRACTION_CHAR2);
    for(int i=0;i<wordcount-1;i++)printf("%d) %s\n",i+1,wordList[i]);
    return 0;
}
void skipWord(){
    int c1=getc(fname);
    while((c1!=EOF)&&(c1!='\n')&&(c1!='\t')&&(c1!=' '))c1=getc(fname);
}
