#include <iostream>
#include <vector>
using namespace std;

// 2. Implement a hash table using Quadratic Probing

// Ans)

class HashTable {
private:
    vector<int> table;
    int size;

    // Simple hash function
    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) {
        size = s;
        table.resize(size, -1); // -1 means empty slot
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;

        // Quadratic probing
        while (table[(index + i*i) % size] != -1 && i < size)
            i++;

        if (i < size)
            table[(index + i*i) % size] = key;
        else
            cout << "Hash table is full, cannot insert " << key << endl;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;

        while (table[(index + i*i) % size] != -1 && i < size) {
            if (table[(index + i*i) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1)
                cout << i << " --> " << table[i] << endl;
            else
                cout << i << " --> " << "EMPTY" << endl;
        }
    }
};

int main() {
    HashTable ht(7); // Table size = 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(5);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table : " << endl;
    ht.display();

    cout << "\nSearching 15 : " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching 99 : " << (ht.search(99) ? "Found" : "Not Found") << endl;

    return 0;
}