// ID : 22011261
// Name : Lee Pei Lin
// Lab : Lab 6 - Array Queue 

#include <iostream>
using namespace std;

class Queue {
private:
    static const int SIZE = 100;
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string name) {
        if (rear == SIZE - 1) {
            cout << "Queue is full. Cannot enqueue " << name << "." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = name;
    }

    void dequeue() {
        if (is_empty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }

    void display_queue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i < rear) cout << " -> ";
        }
        cout << " -> NULL" << endl;
    }

    bool is_empty() {
        return front == -1 || front > rear;
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
