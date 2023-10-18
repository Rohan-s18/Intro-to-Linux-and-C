#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char filename[] = "output.txt";
    char data = 'h';
    int iterations = 0;
    
    while (iterations < 1000000) {
        file = fopen(filename, "a"); 
        
        if (file == NULL) {
            perror("Error opening the file");
            break; 
        }

        fprintf(file,"%c",data); 

        if (fclose(file) != 0) { // Close the file
            perror("Error closing the file");
            break; // Exit the loop on error
        }

        iterations++;

    }

    return 0;
}

