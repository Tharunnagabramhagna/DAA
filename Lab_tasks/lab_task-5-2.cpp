#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 2. Write a program to sort the array elements using Bucket Sort Technique. 
Derive its time complexity */

// Ans)

void bucketSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(),arr.end());

    vector<vector<int>>buckets(maxVal+1);

    for(int x : arr)
        buckets[x].push_back(x);
    
    int idx = 0;

    for(auto& bucket : buckets) {
        for(int x : bucket)
            arr[idx++] = x;
    }
}

int main() {
    int size;

    cout << "Enter the size of the array : ";
    cin >> size;

    vector<int>arr(size);

    for(int i = 0; i < size; i++) {
        cout << "Enter the element of index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array Before Sorting : ";
    for(int val : arr)
        cout << val << " ";
    cout << endl;

    bucketSort(arr);

    cout << "Array After Sorting : ";
    for(int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}