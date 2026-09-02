#include <iostream>
using namespace std;

/* 2. Implement a hash table using Quadratic Probing. */

class hashTable {
private:
    static const int SIZE = 7; // Fixed array size (prime number is best)
    int keys[SIZE];
    int values[SIZE];

    // modulo hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

public:
    hashTable() {
        // Initialize all slots as empty (-1)
        for (int i = 0; i < SIZE; i++) {
            keys[i] = -1; 
            values[i] = -1;
        }
    }

    // 1. Insert key-value pair
    void insert(int key, int value) {
        int idx = hashFunction(key);

        // Quadratic probing: (idx + i^2) % SIZE
        for (int i = 0; i < SIZE; i++) {
            int probeIdx = (idx + i * i) % SIZE;

            // Case A: Slot is empty, deleted, or key already exists
            if (keys[probeIdx] == -1 || keys[probeIdx] == -2 || keys[probeIdx] == key) {
                keys[probeIdx] = key;
                values[probeIdx] = value;
                return;
            }
        }
        cout << "Table is full! Cannot insert " << key << endl;
    }

    // 2. Search for a key's value
    int search(int key) {
        int idx = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int probeIdx = (idx + i * i) % SIZE;

            // If we hit an empty slot, the key definitely does not exist
            if (keys[probeIdx] == -1)
                return -1; 

            // Key found
            if (keys[probeIdx] == key)
                return values[probeIdx];
        }
        return -1; // Key not found after checking entire table
    }

    // 3. Remove a key
    void remove(int key) {
        int idx = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int probeIdx = (idx + i * i) % SIZE;

            if (keys[probeIdx] == -1) {
                cout << "Key " << key << " not found to delete.\n";
                return;
            }

            if (keys[probeIdx] == key) {
                keys[probeIdx] = -2; // Mark as deleted (tombstone)
                values[probeIdx] = -1;
                cout << "Key " << key << " deleted successfully.\n";
                return;
            }
        }
        cout << "Key " << key << " not found to delete.\n";
    }

    // Print current state of the array
    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << "Slot " << i << ": ";
            if (keys[i] == -1) 
                cout << "[EMPTY]\n";
            else if (keys[i] == -2)
                cout << "[DELETED]\n";
            else 
                cout << "(" << keys[i] << " -> " << values[i] << ")\n";
        }
        cout << "---------------------\n";
    }
};

int main() {
    hashTable ht;

    cout << "--- Inserting Elements ---\n";
    ht.insert(10, 100); // 10 % 7 = 3. Goes to slot 3
    ht.insert(17, 200); // 17 % 7 = 3. Collision => Probes to slot (3+1^2)%7=4
    ht.insert(24, 300); // 24 % 7 = 3. Collision => Probes to slot (3+2^2)%7=0
    ht.display();

    cout << "--- Searching ---\n";
    cout << "Value for key 17: " << ht.search(17) << "\n\n";

    cout << "--- Deleting Key 17 ---\n";
    ht.remove(17);      // Slot 4 becomes [DELETED]
    ht.display();

    cout << "--- Searching After Deletion ---\n";
    cout << "Value for key 24: " << ht.search(24) << endl; 

    return 0;
}
