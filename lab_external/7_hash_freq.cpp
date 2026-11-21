/* 7. Given an integer array, use hashing to find the frequency of every distinct element. */


// Algorithm
// 1. Start.
// 2. Read the number of elements.
// 3. Read all array elements.
// 4. Create an empty unordered map.
// 5. Traverse the array.
// 6. Increase the frequency of each element using mp[arr[i]]++.
// 7. Display every distinct element and its frequency.
// 8. Stop.

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    // T.C : O(n) ; S.C : O(n)
    unordered_map<int,int> m;

    // count the frequencies of each element
    for(int val : arr) m[val]++;
    
    cout << "\nElement Frequencies : \n";
    for(auto& p : m)
        cout << p.first << " --> " << p.second << endl;

    return 0;
}