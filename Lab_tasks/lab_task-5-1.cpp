#include <iostream>
#include <vector>
using namespace std;

/* 1.  Write a program to sort the array elements using Merge Sort Technique.
Derive its time complexity */

// Ans)

void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    while (i <= mid)
        temp.push_back(arr[i++]);

    while (j <= end)
        temp.push_back(arr[j++]);
    
    for(int i = 0; i < temp.size(); i++)
        arr[i + st] = temp[i];
}

void mergeSort(vector<int> &arr, int st, int end)
{
    if(st < end) {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid); // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, st, mid, end); // sort and merge the halfs
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    vector<int> arr(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element of index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array Before Sorting : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}