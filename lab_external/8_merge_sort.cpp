// 8) Implement merge sort and explain its time complexity analysis

#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int st, int mid , int end) {
    vector<int> temp;

    int i = st, j = mid + 1;

    // add the elements in sorted order to temp
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else // arr[i] > arr[j]
            temp.push_back(arr[j++]);
    }

    // add the left-overs
    while(i <= mid)
        temp.push_back(arr[i++]);
    
    while(j <= end)
        temp.push_back(arr[j++]);
    
    // place the sorted part in the array
    for(int i = 0; i < temp.size(); i++)
        arr[i+st] = temp[i];
}

void mergeSort(int arr[], int st, int end) {
    // Base Case
    if(st >= end)
        return;
    
    int mid = st + (end - st) / 2;
    mergeSort(arr, st, mid); // left half
    mergeSort(arr, mid + 1, end); // rigt half
    merge(arr, st, mid, end);
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter the size of the array : ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the element of index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array Before Sorting : ";
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Array after Sorting : ";
    display(arr, n);

    return 0;
}