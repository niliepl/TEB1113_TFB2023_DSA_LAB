// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 6 Circular Queue

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
            rear->next = front; 
        } else {
            rear->next = new_node;
            rear = new_node;
            rear->next = front;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        // Only one node
        if (front == rear) {
            cout << "Dequeued: " << front->data << endl;
            delete front;
            front = nullptr;
            rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            cout << "Dequeued: " << temp->data << endl;
            delete temp;
        }
    }

    void display_queue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        cout << "Queue: ";
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != front);
        cout << front->data << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Ali");
    q.enqueue("Bob");
    q.enqueue("Cade");
    q.enqueue("Dina");

    q.display_queue();

    q.dequeue();

    cout << "After dequeueing:" << endl;
    q.display_queue();

    return 0;
}
