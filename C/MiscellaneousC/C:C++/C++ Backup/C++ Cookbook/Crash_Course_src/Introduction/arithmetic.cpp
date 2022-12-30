//
//  arithmetic.cpp
//  Crash_Course_src
//
//  Created by Rohan Singh on 12/23/22.
//
//  This file is an introduction to simple arithmetic operations, functions, operators, flow statements and enumerations
//  In the introductory files, I will be using printf() instead of cout

//  Imports
#include <stdio.h>
#include <cstdio>
#include<array>


//  Enumeration class for different arithmetic operations
enum class Arithmetic_Operator{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO
};

//  Data Classes (structs)
struct Course{
    
    //The data inside the struct
    char *name;
    char *code;
    int credits;
    
    //The functions of the struct
    void print_course(){
        printf("%s: %s (%d Credits)\n",code,name,credits);
    }
    
};

//  Function to find the integer squareroot of a number
int int_sqrt(int n){
    int i = 1;
    while(i*i < n) ++i;
    return i - (i*i!=n);
}

//  Function to get the absolute value of a number
int abs_value(int n){
    if(n > 0)
        return n;
    return n*-1;
}


//  Function that will format and print the different types of int literals
void print_literal_ints(){
    
    //Binary literal
    int a = 0b1010101010;
    
    //Octal literal
    int b = 012345;
    
    //Hexadecimal literal
    int c = 0xFFFF;
    
    //Hexadecimal literal for unsigned long long
    unsigned long long d = 0xFFFFFFFFFFFFFFFF;
    
    //Printing the binary literal
    printf("\n%d\n",a);
    
    //Printing the octal literal
    printf("%d\n",b);
    
    //Printing the hexadecimal int literal
    printf("%d\n",c);
    
    //Printing the unsigned long long hexadecimal literal
    printf("%llu\n",d);
    
}


//  Function to calculate an arithmetic expression given a set of variables and an operator
int operate(int a, int b, Arithmetic_Operator opr){
    
    // Using a switch-case statement
    switch (opr) {
            
        //Given operator is ADD
        case Arithmetic_Operator::ADD:{
            return a + b;
        }break;
            
        //Given operator is SUBTRACT
        case Arithmetic_Operator::SUBTRACT:{
            return a - b;
        }break;
            
        //Given operator is MULTIPLY
        case Arithmetic_Operator::MULTIPLY:{
            return a * b;
        }break;
            
        //Given operator is DIVIDE
        case Arithmetic_Operator::DIVIDE:{
            return a / b;
        }break;
            
        //Given operator is MODULO
        case Arithmetic_Operator::MODULO:{
            return a % b;
        }break;
        
        //Default
        default:
            return -1;
    }
    
}



//  This function is basically an extension of the main method
void demo(){
    
    //Deckaring the variable
    int x = 49;
    
    //Calling the squareroot function
    int y = int_sqrt(x);
    
    //Printing the value
    printf("The Squareroot of %d is: %d\n\n",x,y);
    
    //Printing the value
    printf("The Absolute Value of %d is %d\n\n",-67,abs_value(-67));
    
    //Printing the int literals
    print_literal_ints();
    
    
    //Printing the array
    int arr[] = {1,3,5,7,9,0,8,6,4,2};
    
    //Getting the length of the array
    size_t len = sizeof(arr)/sizeof(int);
    
    printf("\n");
    
    int ct = 1;
    
    //Using a for loop to iterate through an array
    for(size_t i = 0; i < len; i++){
        printf("The %zu-th element of the array is: %d\n",i+1,arr[i]);
        
        ct++;
    }
    
    printf("\n");
    
    
    //Using the Arithmetic Operators Enumeration Class
    Arithmetic_Operator operation = Arithmetic_Operator::ADD;
    int result = operate(10,20,operation);
    printf("The result is: %d\n\n",result);
    
    
    //Using the Course Structs to store data entries for different courses and then using their print methods
    Course java;
    java.name = "Introduction to Java Programming";
    java.code = "CSDS 132";
    java.credits = 3;
    
    Course ds;
    ds.name = "Introduction to Data Structures";
    ds.code = "CSDS 233";
    ds.credits = 4;
    
    Course os{"Introduction to Operating Systems","CSDS 338",4};
    
    java.print_course();
    ds.print_course();
    os.print_course();
    
    printf("\n");
    
}


// Main method of the file
/*
int main(){
    
    demo();
    
    return 0;
    
}
 */

