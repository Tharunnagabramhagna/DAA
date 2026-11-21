// 5. Implement a hash table using a) Linear Probing b) Quadratic Probing

// Algorithm

// 1. Start.
// 2. Read the hash table size.
// 3. Initialize all hash table positions as empty.
// 4. Display the menu:
//    - Linear Probing
//    - Quadratic Probing
//    - Exit
// 5. Select the collision resolution method.
// 6. Perform the required operation:
//    - Insert: Calculate the hash index and find an available position using the selected
//              probing method.
//    - Search: Calculate the hash index and search for the given key.
//    - Delete: Find the key and mark its position as deleted.
//    - Display: Print all hash table elements.
// 7. Repeat until the user selects Exit.
// 8. Stop.

#include <iostream>
using namespace std;

// -1 --> empty ; -2 --> deleted
// method-1 : Linear Probing, method-2 : Quadratic Probing

class hashTable
{
    int size;
    int *keys, *values;

public:
    hashTable(int s)
    {
        size = s;
        keys = new int[size];
        values = new int[size];

        // Intitialize all the values of arrays as empty
        for (int i = 0; i < size; i++)
        {
            keys[i] = -1;
            values[i] = -1;
        }
    }

    // Find the table position
    int position(int key, int i, int method)
    {
        if (method == 1)
            return (key % size + i) % size; // linear probing

        return (key % size + i * i) % size; // quadratic probing
    }

    void insert(int key, int val, int method)
    { // O(n)
        for (int i = 0; i < size; i++)
        {
            int probeIdx = position(key, i, method);

            // case-1 : When the position is empty (-1)
            // case-2 : When the position got deleted (-2)
            // case-3 : When the position already exists --> (get it replaced by new value)
            if (keys[probeIdx] == -1 || keys[probeIdx] == -2 ||
                keys[probeIdx] == key)
            {
                keys[probeIdx] = key;
                values[probeIdx] = val;
                cout << "Inserted the key value pair successfully!\n";
                return;
            }
        }
        cout << "Hash Table is Full!\n";
    }

    void search(int key, int method)
    { // O(n)
        for (int i = 0; i < size; i++)
        {
            int idx = position(key, i, method);

            if (keys[idx] == -1)
                break;

            if (keys[idx] == key)
            {
                cout << "Value : " << values[idx] << endl;
                return;
            }
        }
        cout << "Key not found!\n";
    }

    void Delete(int key, int method)
    { // O(n)
        for (int i = 0; i < size; i++)
        {
            int idx = position(key, i, method);

            if (keys[idx] == -1)
                break;

            if (keys[idx] == key)
            {
                keys[idx] = -2;
                values[idx] = -1;
                cout << "Deleted the key successfully!\n";
                return;
            }
        }
        cout << "Key not found!\n";
    }

    void display()
    { // O(n)
        cout << "\nElements of Hash Table :\n";
        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";

            if (keys[i] == -1)
                cout << "EMPTY";
            else if (keys[i] == -2)
                cout << "DELETED";
            else
                cout << keys[i] << " -> " << values[i];

            cout << endl;
        }
    }
};

int main()
{
    int size;

    cout << "Enter the size of the hash table : ";
    cin >> size;

    hashTable ht(size);

    int method, choice, key, val;
    cout << "Choose a method : \n";
    cout << "1. Linear Probing\n2. Quadratic Probing\n";
    cout << "Enter your choice (1-2) : ";
    cin >> method;

    while (true)
    {
        cout << "\n-- Hash Table Functions --\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5.Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the required key and value : ";
            cin >> key >> val;
            ht.insert(key, val, method);
            break;
        case 2:
            cout << "Enter key : ";
            cin >> key;
            ht.Delete(key, method);
            break;
        case 3:
            cout << "Enter key : ";
            cin >> key;
            ht.search(key, method);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Exiting...";
            return 0;

        default:
            cout << "\nInvalid choice!\n";
        }
    }

    return 0;
}