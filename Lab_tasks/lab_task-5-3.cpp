#include <iostream>
#include <vector>
using namespace std;

/* 3. Write a program to sort the array elements using Quick Sort Technique.
Derive its time complexity */

// Ans)

int partition(vector<int> &arr, int st, int end)
{
    int pivot = arr[end], i = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int pivotIdx = partition(arr, st, end);
        quickSort(arr, st, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);
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
        cout << "Enter the element of index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array Before Sorting : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Array after Sorting : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}