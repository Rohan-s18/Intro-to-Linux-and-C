#include <stdio.h>
#define LINES

void showPage( FILE * );

int main( int argc, char **argv){
    FILE *fp;
    int exit_code = 0;
    if(argc != 2){
        fprintf(stderr, "Usage: Head <filename>\n");
        exit_code = 1;
    }
    else if((fp = fopen(argv[1],"r")) == NULL){
        fprintf(stderr,"Error opening file!\n");
        exit_code = 2;
    }
    else{
        showPage(fp);
        fclose(fp);
    }
    return exit_code;
}

void showPage( FILE *fp){
    int count = 0;
    char line[81];
    while(count < LINES && fgets(line,81,fp) != NULL){
        fputs(line,stdout);
        ++count;
    }
}