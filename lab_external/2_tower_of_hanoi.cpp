/* 2Q. Tower of Hanoi – Recursive and Non-Recursive */

// Concept:
// We have three rods:
// - Source (A)
// - Auxiliary (B)
// - Destination (C)
// Our objective is to move all disks from A to C.

// Rules:
// 1. Move only one disk at a time.
// 2. Only the top disk can be moved.
// 3. A bigger disk cannot be placed on a smaller disk.

// Formula for number of moves is " 2^n - 1 "

// Time Complexity : O(2^n)
// Space Complexity : O(n)

// Algorithm

// 1. Start.
// 2. Read the number of disks n.
// 3. Consider three rods: Source (A), Auxiliary (B) and Destination (C).
// 4. If there is only one disk, move it directly from Source to Destination.
// 5. Otherwise, divide the problem into smaller disk movements.
// 6. Move the upper n-1 disks from Source to Auxiliary using Destination.
// 7. Move the largest disk from Source to Destination.
// 8. Move the remaining n-1 disks from Auxiliary to Destination using Source.
// 9. Repeat the movements until all disks reach the Destination rod.
// 10. Display the sequence of disk movements.
// 11. Stop.

#include <iostream>
#include <stack>
using namespace std;

void towerOfHanoiRec(int n, char A, char B, char C)
{
    // Base Case
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << A << " to " << C << endl;
        return;
    }

    // Recursive Cases
    towerOfHanoiRec(n - 1, A, C, B); // move more than 1 disk from source to auxiliary

    cout << "Move disk " << n << " from " << A << " to " << C << endl;

    towerOfHanoiRec(n - 1, B, A, C); // move more than 1 disk from auxiliary to destination
}

void moveDisk(stack<int> &from, stack<int> &to, char a, char b)
{
    if (from.empty())
    {
        int x = to.top();
        to.pop();
        from.push(x);
        cout << "Move Disk " << x << " from " << b << " to " << a << endl;
    }
    else if (to.empty())
    {
        int x = from.top();
        from.pop();
        to.push(x);
        cout << "Move Disk " << x << " from " << a << " to " << b << endl;
    }
    else if (from.top() < to.top())
    {
        int x = from.top();
        from.pop();
        to.push(x);
        cout << "Move Disk " << x << " from " << a << " to " << b << endl;
    }
    else
    { // from.top() >= to.top()
        int x = to.top();
        to.pop();
        from.push(x);
        cout << "Move Disk " << x << " from " << b << " to " << a << endl;
    }
}

void towerOfHanoiIter(int n)
{
    stack<int> A, B, C;

    // step-1 : push all the disks to source
    for (int i = n; i >= 1; i--)
        A.push(i);

    /* knowledge purpose */
    // char dest = 'C', aux = 'B';

    // // E.g. if disks are 2 then start with moving first disk from A to B
    // if (n % 2 == 0)
    //     swap(dest, aux);

    int total = (1 << n) - 1; // 2^n - 1

    for (int i = 1; i <= total; i++)
    {
        if (i % 3 == 1)
            moveDisk(A, C, 'A', 'C');
        else if (i % 3 == 2)
            moveDisk(A, B, 'A', 'B');
        else // i % 3 == 0 (or) 3,4,5,....
            moveDisk(B, C, 'B', 'C');
    }
}

int main()
{
    int n;

    cout << "Enter the number of disks : ";
    cin >> n;

    if (n < 1 || n > 20)
    {
        cout << "Enter the number of disks between 1 to 20." << endl;
        return 0;
    }

    cout << "\nRecursive Solution : \n";
    towerOfHanoiRec(n, 'A', 'B', 'C');

    cout << "\nIterative Solution : \n";
    towerOfHanoiIter(n);

    return 0;
}