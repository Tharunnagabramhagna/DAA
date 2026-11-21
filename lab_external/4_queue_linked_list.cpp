// 4. Write a program to implement Queue operations using Linked List.

// Algorithm

// Enqueue:
// 1. Create a new node.
// 2. Store the value.
// 3. If the queue is empty, make both front and rear point to the new node.
// 4. Otherwise, connect the new node to rear and update rear.

// Dequeue:
// 1. Check whether the queue is empty.
// 2. If empty, display Queue Underflow.
// 3. Otherwise, delete the front node.
// 4. Update front to the next node.
// 5. If front becomes NULL, update rear to NULL.

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node *front, *rear;
public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int val) { // O(1)
        Node* newNode = new Node(val);
        if(rear == nullptr)
            front = rear = newNode;
        else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << val << " enqueued.\n";
    }

    void dequeue() { // O(1)
        if(front == nullptr || rear == nullptr) {
            cout << "Queue underflow.\n";
            return;
        }
        cout << front->data << " dequeued.\n";
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    void peek() { // O(1)
        if(front == nullptr || rear == nullptr) {
            cout << "Queue underflow.\n";
            return;
        }
        cout << "Front Element : " << front->data << endl;
    }

    void display() { // O(n)
        if(front == nullptr || rear == nullptr) {
            cout << "Queue underflow.\n";
            return;
        }
        cout << "Elements of Queue : \n";
        for(Node* temp = front; temp != nullptr; temp = temp->next)
            cout << temp->data << " ";
    }
};

int main() {
    Queue q;
    int choice, val;

    while(true) {
        cout << "\n--Queue using Linked List--\n";
        cout << "1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "\nEnter the value : ";
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
            case 5: return 0;

            default : cout << "Invalid choice!\n";
        }
    }

    return 0;
}