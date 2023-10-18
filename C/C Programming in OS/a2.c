#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main() {
    int iteration = 0;
    
    while (1) {
        size_t size = sizeof(int); 
        void *ptr = malloc(size);

        if (ptr == NULL) {
            perror("malloc failed");
            break; 
        }

        iteration++;
        //printf("Allocation iteration %d\n", iteration);
        sleep(1);

        free(ptr);
    }

    return 0;
}
