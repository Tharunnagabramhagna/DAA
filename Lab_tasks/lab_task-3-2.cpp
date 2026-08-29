#include <iostream>
using namespace std;

/* 2. Write a program to implement Stack operations using Linked List. */

// Ans)

// Node class
class Node {
public:
    int data;
    Node* next;
    Node(int val) { // constructor
        data = val;
        next = NULL;
    }
};

// Stack class using linked list
class Stack {
    Node* top; // pointer to top
public:
    Stack() { top = NULL; }

    // Push element
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed\n";
    }

    // Pop element
    void pop() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return;
        }
        cout << top->data << " popped\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek top element
    void peek() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return;
        }
        cout << "Top = " << top->data << endl;
    }

    // Display stack
    void display() {
        if (top == NULL) {
            cout << "Stack Empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
