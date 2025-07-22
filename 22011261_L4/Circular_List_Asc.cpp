/*
ID : 22011261
Name : Lee Pei Lin
Lab : Lab 4  Circular list (forward)
*/

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        next = nullptr;
        
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Bob");
    Node* node3 = new Node("Cade");

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;


    Node* current = node1;
    do{
        cout << current->data << " ";
        current = current->next;
       
    }while (current != node1);
    cout << current->data << " ";
    
    cout << endl;



    return 0;
}