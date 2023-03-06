//  Author: Rohan Singh
//  Code for a Graph in C++

//  Imports
#include <iostream>

using namespace std;

//  Class for Graph
class Graph{

    private:

    class Node{

        public: 
        Node* neighbors;
        string name;

    };

    int numNodes;
    Node* source;
    Node* nodes;

    int indexOf(string nodeName){
        for(int i = 0; i < this->numNodes; i++){
            if(nodes[i].name == nodeName)
                return i;
        }
        return -1;
    }
    

    public:

    Graph(){
        this->numNodes = 0;
        this->nodes = (Node*)malloc(sizeof(Node)*100);
    }

    void addNode(string name){

    }

    void addConnection(string from, string to){

    }



};




//  Main function
int main(){
    return 0;
}