//  Author: Rohan Singh
//  30/12/2022
//  This code will demoinstrate Excepions and Exception handling in C++

//  Imports 
#include <cstdio>
#include <stdexcept>


//  Creating a class that will throw an exception if an incorrect password is given during Login
class Login{
    private:
    int password;

    public:

    //Constructor
    Login(int pwd){
        //Setting the Password
        password = pwd;
    }

    void login(int code){

        //Successful Login
        if(code==password){
            printf("Welcome Back!\n");
        }
        //Unsuccessful Login
        else{
            //Throwing an exception
            throw std::runtime_error("Intruder Alert.");
        }

    }


};


//  Main method to demonstrate how to handle the exception
int main(){

    //Instantiating a Login Object
    Login* my_login = new Login(1811);

    //To handle exceptions, you cover the code with a try-catch block
    //The try block runs the code and switch block runs if an exception is thrown
    try{
        //Correct
        my_login->login(1811);
        //Incorrect
        my_login->login(1118);
    }
    catch(const std::exception& e){
        //The exception block
        printf("Exception caught with message: %s\n", e.what());
    }
        
    return 0;
}
