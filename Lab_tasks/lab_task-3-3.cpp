/* 3. Write a program to implement Queue operations using Linked List. */

// Ans)

#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Queue class using linked list
class Queue {
    Node* front; // first element
    Node* rear;  // last element
public:
    Queue() { front = rear = NULL; }

    // Enqueue (insert at rear)
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued\n";
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Empty\n";
            return;
        }
        cout << front->data << " dequeued\n";
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL; // queue empty
        delete temp;
    }

    // Peek front element
    void peek() {
        if (front == NULL) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Front = " << front->data << endl;
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Queue Empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;

    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
