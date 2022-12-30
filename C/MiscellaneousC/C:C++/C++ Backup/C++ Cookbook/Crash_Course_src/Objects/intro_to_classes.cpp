//
//  intro_to_classes.cpp
//  Crash_Course_src
//
//  Created by Rohan Singh on 12/27/22.
//
//  This file contains source code to explain how classes works in C++


#include <stdio.h>
#include <cstdio>
#include <string>
using namespace std;


class Employee{
    
    //This will be private ;)
private:
    
    //Attributes of the employee class
    string name;
    int employee_id;
    string profession;
    string boss;
    
public:
    
    //Constructor
    Employee(string name, int employee_id, string profession, string boss){
        this->name = name;
        this->employee_id = employee_id;
        this->profession = profession;
        this->boss = boss;
    }
    
    //Simple method to print the attributes of the employee
    void print_employee_card(){
        printf("Name: %s\nEmployee id: %d\nPosition: %s\nBoss: %s\n",this->name.c_str(),this->employee_id,this->profession.c_str(),this->boss.c_str());
    }
    
};


//  Demonstrationn method
void class_demo(){
    
    //Constructing a few employee objects
    Employee* michael = new Employee{"Michael Scott",111,"Regional Manager","David Wallace"};
    Employee* dwight = new Employee{"Dwight Schrute",222,"Assistant Regional Manager","Michael Scott"};
    Employee* jim = new Employee{"Jim Halpert",333,"Salesman","Michael Scott"};
    
    //Using the methods of these objects
    michael->print_employee_card();
    printf("\n");
    
    dwight->print_employee_card();
    printf("\n");
    
    jim->print_employee_card();
    printf("\n");
    
}


//  Main method
int main(){
    
    printf("Hello World!\n");
    
    printf("\n");
    
    class_demo();
    
    printf("\n");

    
    
}
