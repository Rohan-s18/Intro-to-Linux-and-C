#include <stdio.h>

int main(int argc, char const *argv[])
{
    int this_is_a_number;
 
    printf( "Please enter a number: " );
    scanf( "%d", &this_is_a_number );
    printf( "You entered %d", this_is_a_number );
    getchar();
    return 0;
}
