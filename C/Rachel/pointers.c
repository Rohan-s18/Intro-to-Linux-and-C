//  Author: Rohan Singh
//  Code for Pointers in C that I made for beautiful Rachel Tjarksen to understand how pointers work in C
//  3/10/2023: Another beautiful day in Cleveland Ohio!


//  Imports
#include <stdio.h>
#include <stdlib.h>

//  Pointers are a very cool type of variable that stores the memory address of a variable
//  You can make a pointer point to a variable by using the "&" operator in front of the variable you want it to point to
//  You can access the value of the variable pointed by the pointer by using the "*" operator

//  Method headers
void incr_var(int x);
void incr_ptr(int* p);

//  Main function!!!
int main(){

    //Variable!
    int x = 10;

    //Pointer!
    int* p;
    //The "&" operator returns the memory address for the variable 'x' and is now stored by the pointer
    p = &x;

    printf("The value of the variable is: %d\n",x);
    printf("The address of the variable is: %p\n",p);
    printf("The value of the variable pointed by the pointer is: %d\n",*p);


    //You might say "but wait, why do we need pointers?""
    //And I would respond "Oh Rachel! You're so pretty!"

    //C is pass by value, so argument values are copied when you call a method, so it won't change it outside the method

    printf("\n\n");
    int y = 10;

    printf("The value of x is: %d\n",x);
    printf("The value of y is: %d\n",y);

    //Calling the increase variable method on x
    incr_var(x);

    //Calling the increase pointer method on the pointer to y, "&y" is the pointer (address of y)
    incr_ptr(&y);

    printf("\nIncreasing Values!\n\n");

    printf("The value of x is: %d\n",x);
    printf("The value of y is: %d\n",y);


    return 0;

}

//  C is pass by value, so the arguments are just copies of the value stored in the variable
//  This means that when you change the variable inside a method, you are only changing the value of a copy

//  Implementation of incr
void incr_var(int x){
    //This only changes the value of the copy of the variable
    x++;
}


//  Another implementation of incr
void incr_ptr(int* p){
    //using a pointer makes sense here, because if you have a copy of the address, you can still "dereference" the actual variable
    (*p)++;
}
