#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 4. Given an integer array, use hashing to find the frequency of every distinct element. */

// Ans)

void frequencyCount(const vector<int>& arr) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    // Display results
    cout << "Element frequencies:\n";
    for (auto& pair : freq) {
        cout << pair.first << " --> " << pair.second << endl;
    }
}

int main() {
    vector<int> arr = {10, 20, 10, 30, 20, 10, 40};

    frequencyCount(arr);

    return 0;
}