#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char my_name[8];
    printf("The address location of my_name is: %p\n",my_name);
    strcpy(my_name,"Rohan");
    printf("The value of my_name : %s\n",my_name);
    return 0;
}
