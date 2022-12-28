//
//  Pointers.cpp
//  Crash_Course_src
//
//  Created by Rohan Singh on 12/23/22.
//
//  The purpose of this file is to go over pointers in C++
//  If you are familiar with pointers in C, then this would be a breeze for you

//Imports
#include <stdio.h>
#include <cstdio>


//  Data Class (struct)
struct CWRU_Course{
    
    //The data inside the struct
    private:
        char *name;
        char *code;
        int credits;
        char *prof;
    
        //The function to set the credits of the course
        bool set_credits(int n){
            credits = n;
            return true;
        }
    
        //The function to set the name of the course
        bool set_name(char *c_name){
            name = c_name;
            return true;
        }
    
        //The function to set the code of the course
        bool set_code(char *c_code){
            code = c_code;
            return true;
        }
    
    public:
    
        //Constructor for the struct
        CWRU_Course(char *course_name, char *course_code, int creds){
            set_name(course_name);
            set_code(course_code);
            set_credits(creds);
            prof = "To be announced";
        }
    
        //The functions of the struct
        void print_course(){
            printf("%s: %s (%d Credits)\nInstructor: %s\n\n",code,name,credits,prof);
        }
    
        bool change_prof(char *prof_name){
            prof = prof_name;
            return true;
        }
    
};

//  Method to demonstrate the creation and deference-ion? of a pointer
void change_foo(){
    
    //Simple int foo
    int foo = 10;
    
    //Pointer to foo
    int* foo_pointer = &foo;
    
    printf("The value of foo is: %d\n",foo);
    printf("The address of foo is :%p\n",foo_pointer);
    printf("The address of foo_pointer is :%p\n",&foo_pointer);
    
    //Dereferencing the foo_pointer and changing its value to 20
    *foo_pointer = 20;
    printf("The value of foo is: %d\n",foo);
    
}

//  Demonstration of pointers to Structs
void struct_pointer(){
    
    //Instantiating the struct
    CWRU_Course java {"Introduction to Java","CSDS 132",3};
    
    java.print_course();
    
    //Creating a pointer to the struct
    CWRU_Course* java_ptr = &java;
    
    printf("The address location of the struct is :%p\n\n",java_ptr);
    
    //Using the "->" operator is basically the same as the dereferencer plus the dot
    java_ptr->print_course();
    
    //Changing the professor using the pointer
    java_ptr->change_prof("Harold Connamacher");
    
    //Seeing the updated course
    java.print_course();
    
}


//  Helper function to print the course details for a given array of courses
void print_courses(CWRU_Course courses[], size_t n_courses){
    
    //Traversing through the array
    for(int i = 0; i < n_courses; i++){
        //Using the print course method
        courses[i].print_course();
    }
    
}


//  Demonstration of Arrays as pointers
void array_pointer(){
    
    //Creating an array of Structs
    CWRU_Course my_courses[] = {{"Quantum Computing","CSDS 386",3},{"Computer Security","CSDS 444",3},{"Embedded Systems Design","ECSE 488",3}};
    
    //Getting the length of the array
    size_t len = sizeof(my_courses)/sizeof(my_courses[0]);
    
    //Using the print courses method
    printf("Printing the courses using an array\n");
    print_courses(my_courses,len);
    
    //Starting from the beginning
    CWRU_Course* my_courses_ptr = &my_courses[0];
    
    printf("Printing the courses using a pointer\n");
    print_courses(my_courses_ptr, len);
    
    //Starting form the second element
    CWRU_Course* my_courses_ptr2 = &my_courses[1];
    
    printf("Printing the courses using a pointer form the second element\n");
    print_courses(my_courses_ptr2, len-1);
    
}


//  Function to print the substrings of a given string
void print_substrings(char* str, int len){
    
    //An integer counter to move during each iteration
    int ct =0;
    
    //Iterating till we reach the end
    while(ct < len){
        printf("%s\n",str+ct);
        ct++;
    }
    
}

//  Showing an example of buffer overflows using pointers
void buffer_overflow_demo(){
    
    //Buffer Overflow means that the memory allocated to one object flows into another one
    //In this case we will be using 2 strings to demonstrate that
    
    char* string_1 = "Hello World";
    char* string_2 = "My Name is Rohan";
    
    //Printing the original strings
    printf("String 1: %s\nString 2: %s\n",string_1,string_2);
    
    //Adding an exclamation point
    *(string_1+13)='!';
    
    //Printing the new Strings
    printf("String 1: %s\nString 2: %s\n",string_1,string_2);
    
    
}


//  Demo method is an extension of the main method, this is going to be the first method that will be pushed onto the call stack
void pointers_demo(){
    
    //printf("Hello World!\n");
    
    //Calling the change_foo method which demonstrates how pointers work
    change_foo();
    
    printf("\n");
    
    //Calling the struct_pointer method which demonstrates how pointers to structs work
    struct_pointer();
    
    printf("\n");
    
    array_pointer();
    
    printf("\n");
    
    //UNcomment this, but it will produce a problem
    //buffer_overflow_demo();
    
    print_substrings("Hello World!",sizeof("Hello World")/sizeof(char));
    
    printf("\n");
}


//Main method of the file (Uncomment to Run)

/*
int main(){
    
    pointers_demo();
    
    return 0;
}
 */
