// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 5 - Simple Stack (Linked List)

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

class Stack {
public:
    Node* top;
    int max_size;
    int current_size;

    Stack(int size) {
        top = nullptr;
        max_size = size;
        current_size = 0;
    }

    void push(string data) {
        if (current_size == max_size) {
            cout << "Stack is full. Cannot push \"" << data << "\"." << endl;
            return;
        }

        Node* new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        current_size++;
        cout << "Pushed: " << data << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        cout << "Popped: " << temp->data << endl;
        top = top->next;
        delete temp;
        current_size--;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to peek." << endl;
        } else {
            cout << "Top of stack: " << top->data << endl;
        }
    }
};

int main() {
    Stack stack(3); 

    stack.push("Ali");
    stack.push("Bob");
    stack.push("Cade");
    stack.push("Dina"); 

    stack.peek();    

    stack.pop();     
    stack.peek();   

    return 0;
}
