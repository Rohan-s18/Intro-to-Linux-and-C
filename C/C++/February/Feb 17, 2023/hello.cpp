#include <cstdio>
#include <iostream>

using namespace std;

void print_names(string arr[], int size);

int main(){

    printf("Hell World!\n");

    cout << "My name is Rohan!\n";

    string friends[] = {"Emile","Ashraf","Rohith","Alden"};

    print_names(friends,4);

    return 0;

}

void print_names(string arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] + "\n";
}
