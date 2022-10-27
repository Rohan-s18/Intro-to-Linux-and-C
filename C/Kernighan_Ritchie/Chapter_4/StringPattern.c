//
// Created by Rohan Singh on 5/26/22.
//
#include <stdio.h>
#include <strings.h>
#define LINE_LIMIT 1000
#define READ_FILEPATH "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_4/Original.txt"
#define WRITE_FILEPATH "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_4/Verified.txt"
#define PATTERN "ould"
int getLine(char str[], char filepath[], int lineNumber);
int numLines(char filepath[]);
int checkPattern(char str[], char pattern[]);
int main(){
    char str[LINE_LIMIT];
    FILE *writeFile;
    writeFile = fopen(WRITE_FILEPATH,"w");
    int lineCount = 0;
    int max = numLines(READ_FILEPATH);
    while(getLine(str,READ_FILEPATH, lineCount) > 0 && lineCount <= max){
        if(checkPattern(str,PATTERN)>0)
            fprintf(writeFile,"%s",str);
        lineCount++;
    }
    return 0;
}
int getLine(char str[], char filepath[], int lineNumber){
    FILE *readfile;
    readfile = fopen(filepath,"r");
    char c;
    int index = 0;
    int lineCount = 0;
    while((c = getc(readfile))!=EOF && lineCount <= lineNumber){
        if(lineCount==lineNumber)
            str[index++] = c;
        if(c=='\n')
            lineCount++;
    }
    str[index] = '\0';
    return strlen(str);
}
int numLines(char filepath[]){
    FILE *readfile;
    readfile = fopen(filepath,"r");
    char c;
    int count = 0;
    while((c= getc(readfile))!=EOF){
        if(c=='\n')
            count++;
    }
    return count;
}
int checkPattern(char str[], char pattern[]){
    for(int i = 0; i < strlen(str); i++){
        if(str[i]==pattern[0]){
            int j = 1;
            for(j = 1; j < strlen(pattern) && str[i+j] == pattern[j]; j++);
            if(j== strlen(pattern))
                return i;
        }
    }
    return -1;
}


