#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

/* 1. Converting recursive programs to non-recursive programs. Towers
of Hanoi Problem example.

a. Implement using Recursion
b. Implement without Recursion */

// Ans)
// a. (Recursive function)
void hanoiRec(int n, char from, char to, char aux) {
    if (n == 0) return; // no disk
    hanoiRec(n - 1, from, aux, to); // move n-1 to aux
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoiRec(n - 1, aux, to, from); // move n-1 to dest
}

// b. (Helper for iterative moves)
void moveDisk(char from, char to, stack<int> &src, stack<int> &dest) {
    if (src.empty()) {
        src.push(dest.top());
        cout << "Move disk " << src.top() << " from " << to << " to " << from << endl;
        dest.pop();
    } else if (dest.empty()) {
        dest.push(src.top());
        cout << "Move disk " << dest.top() << " from " << from << " to " << to << endl;
        src.pop();
    } else if (src.top() > dest.top()) {
        src.push(dest.top());
        cout << "Move disk " << src.top() << " from " << to << " to " << from << endl;
        dest.pop();
    } else {
        dest.push(src.top());
        cout << "Move disk " << dest.top() << " from " << from << " to " << to << endl;
        src.pop();
    }
}

// Iterative function
void hanoiIter(int n, char from, char to, char aux) {
    stack<int> src, dest, helper;
    for (int i = n; i >= 1; i--) src.push(i); // fill source

    int totalMoves = pow(2, n) - 1;
    if (n % 2 == 0) swap(to, aux); // even case

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) moveDisk(from, to, src, dest);
        else if (i % 3 == 2) moveDisk(from, aux, src, helper);
        else moveDisk(aux, to, helper, dest);
    }
}

int main() {
    int n = 3; // number of disks

    cout << "Recursive solution:\n";
    hanoiRec(n, 'A', 'C', 'B');

    cout << "\nIterative solution:\n";
    hanoiIter(n, 'A', 'C', 'B');

    return 0;
}
