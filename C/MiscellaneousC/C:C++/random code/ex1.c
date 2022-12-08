#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
        printf(“PID of ex1.c = %d\n”,getpid());
        execv(“./ex2”);
        printf(“Back to ex1.c”);
        return 0;
}
