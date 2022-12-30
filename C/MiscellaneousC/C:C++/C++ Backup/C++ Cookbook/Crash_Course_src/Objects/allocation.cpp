//
//  allocation.cpp
//  Crash_Course_src
//
//  Created by Rohan Singh on 12/27/22.
//
//  This file contains source code to explain how allocation of storage works in C++

#include <stdio.h>
#include <cstdio>



void dynamic_storage(){
    
    //This is how a dynamic object is allocated
    int *my_ptr = new int{30};
    printf("The value of the object is: %d\n",*my_ptr);
    
    //This is how a dynamic object is deallocated
    
    delete my_ptr;
    
    printf("The value of the object is: %d\n",*my_ptr);
    
}

//  This code snippet will help us track the construction and destruction of an object in C++
struct Tracer{
    private:
    char* name;
    
    public:
    
    //Constructor (this is called during allocation)
    Tracer(char* str){
        name = str;
        printf("Tracer object with name: %s has been created :D\n",name);
    }
    
    //Destructor (this is called during deallocation)
    ~Tracer(){
        printf("Tracer object with name: %s has been destroyed ;-; \n",name);
    }
    

};

//  This method will demonstrate allocation and deallocation of memory for a Tracer Object
void tracer_demo(){
    
    //Constructing a Tracer object
    Tracer* my_obj = new Tracer{"Alessandra"};
    
    //Destructing a Tracer object
    delete my_obj;
    
}



//  This demonstration method is an extension of the main method
void allocation_demo(){
    //printf("Hello World!\n");
    
    dynamic_storage();
    
    printf("\n");
    
    tracer_demo();
    
    printf("\n");
    
}


//  Main method (uncomment to run)
/*
int main(){
    
    //Calling the demo method
    allocation_demo();
    
    return 0;
}
*/
