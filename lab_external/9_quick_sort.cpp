// 9. Implement quick sort and analyse its time complexity analysis

// Algorithm

// Quick Sort:
// 1. Start.
// 2. Select the last element as pivot.
// 3. Partition the array around the pivot.
// 4. Place the pivot in its correct position.
// 5. Recursively sort the left subarray.
// 6. Recursively sort the right subarray.
// 7. Stop when the subarray contains zero or one element.

// Partition:
// 1. Select the last element as pivot.
// 2. Initialize i = low - 1.
// 3. Traverse the array from low to high-1.
// 4. If the current element is smaller than or equal to the pivot, increment i and swap elements.
// 5. Finally, swap the pivot with the element at i+1.
// 6. Return the pivot position.

// T.C : O(n logn) ; S.C : O(n)

#include <iostream>
using namespace std;

int partition(int arr[], int st, int end)
{
    int pivot = arr[end], i = st-1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }

    swap(arr[i + 1], arr[end]);

    return i + 1;
}

void quickSort(int arr[], int st, int end)
{
    if (st >= end)
        return;

    int pivotIdx = partition(arr, st, end);

    quickSort(arr, st, pivotIdx - 1);  // left half
    quickSort(arr, pivotIdx + 1, end); // right half
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;

    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Array Before Sorting : ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nArray After Sorting : ";
    display(arr, n);

    return 0;
}