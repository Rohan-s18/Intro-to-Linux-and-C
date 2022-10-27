//
// Created by Rohan Singh on 5/18/22.
//

#include <stdio.h>
#define INPUT_FILE "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_2/MixedCase.txt"
#define OUTPUT_FILE "/Users/rohansingh/Desktop/summer22/Kernighan_Ritchie/Chapter_2/UCase.txt"
int main(){
    FILE *infile;
    FILE *outfile;
    if((infile=fopen(INPUT_FILE,"r"))==NULL)return -1;
    outfile=fopen(OUTPUT_FILE,"w");
    int c;
    while((c=getc(infile))!=EOF){
        c=(c>='a'&&c<='z')?c-='a'-'A':c;
        putc(c,outfile);
    }
    return 0;
}

