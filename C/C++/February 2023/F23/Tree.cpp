//  Author: Rohan Singh
//  February 23, 2023
//  Code for a Tree in C++

#include <iostream>

using namespace std;

//  Class for a Binary Search Tree
class Tree{
    
    private:

    class Node{
        public:

        //Key for the Node
        int key;

        //Value for the Node
        string val;
        
        //Pointers to the children
        Node* left_child;
        Node* right_child;

        Node(int my_key, string name){
            this->key = my_key;
            this->val = name;
        }


    };

    Node *root;
    int num;


    public:

    Tree(){
        this->num = 0;
    }

    void add(int x, string y){
        if(num==0){
            this->root = new Node(x, y);
            num++;
            return;
        }

        Node* trav = root;
        bool added = false;
        while(!added){
            if(x <= trav->key){
                if(trav->left_child == NULL){
                    trav->left_child = new Node(x, y);
                    num++;
                    added = true;
                }
                else
                    trav = trav->left_child;
            } 
            else{
                if(trav->right_child == NULL){
                    trav->right_child = new Node(x, y);
                    num++;
                    added = true;
                }
                else
                    trav = trav->right_child;
            }
                
        }


    }

};


int main(){

    return 0;
}