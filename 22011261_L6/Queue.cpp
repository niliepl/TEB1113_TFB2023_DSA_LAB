// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 6 - Queue (Linked List)

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string data) {
        Node* new_node = new Node(data);

        if (front == nullptr) {
            front = new_node;
            rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        cout << "Dequeued: " << temp->data << endl;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Bob");
    q.enqueue("Cade");

    q.display_queue();

    q.dequeue();

    cout << "After dequeueing:" << endl;
    q.display_queue();

    return 0;
}

