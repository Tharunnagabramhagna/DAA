// 3. Stack Operations Using Linked List

// Algorithm

// Push operation
// 1. Create a new node.
// 2. Store the given value.
// 3. Point the new node to the current top.
// 4. Update top to the new node.

// Pop operation
// 1. Check whether the stack is empty.
// 2. If empty, display Stack Underflow.
// 3. Otherwise, store the top node temporarily.
// 4. Move top to the next node.
// 5. Delete the previous top node.

// Display operation
// 1. Start from top.
// 2. Traverse each node.
// 3. Print its value.
// 4. Stop when NULL is reached.

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

class Stack {
public:
    Node* top;

    Stack() {
        top = nullptr;
    }

    void push(int val) { // O(1)
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << val << " pushed successfully.\n";
    }

    void pop() { // O(1)
        // Edge Case
        if(top == nullptr) {
            cout << "Stack Underflow.\n";
            return;
        }
        cout << top->data << " popped successfully.\n";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() { // O(1)
        // Edge Case
        if(top == nullptr) {
            cout << "Stack Underflow.\n";
            return;
        }
        cout << "Top Element : " << top->data << endl;
    }

    void display() { // O(n)
        cout << "Elements of Stack : ";
        for(Node* temp = top; temp != nullptr; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;
    }
};

int main() {
    Stack s;

    int val, choice;

    while(true) {
        cout << "\n--Stack Operations using Linked List--\n";
        cout << "1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit";
        cout << "\nEnter your choice : ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter the value : ";
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
            
            default: cout << "Invalid Choice.\n";
        }
    }

    return 0;
}