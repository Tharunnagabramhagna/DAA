/* 1Q) Program to find Kth Smallest no. in a given array with various approaches. */

// 1) Start
// 2) Read the number of elements n.
// 3) Read the array elements.
// 4) Read the value of k.
// 5) Check whether k is valid (1 <= k <= n).
// 6) Apply an appropriate technique to find the Kth smallest element:
//      - Sorting: Sort the array in ascending order.
//      - Min Heap: Construct a min heap and remove the minimum element k-1 times.
//      - Quick Select: Partition the array around a pivot and locate the element at index k-1.
// 7) Display the Kth smallest element.
// 8) Stop.

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 1st approach - sorting
int sortSearch(int arr[], int k, int n)
{
    // step-1 : Sort the array
    sort(arr, arr + n);

    // step-2 : Return the final result
    return arr[k - 1];
}

// 2nd approach - minHeap
int minHeapSearch(int arr[], int k, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    // step-1 : Insert all elements of arr to pq
    for (int i = 0; i < n; i++)
        pq.push(arr[i]);

    // step-2 : Pop the first k-2 min elements
    for (int i = 0; i < k - 1; i++)
        pq.pop();

    // step-3 : Return the (k-1)th idx element as final result
    return pq.top();
}

// 3rd approach - quick select (similar to quick sort)

// partition logic same as quick sort
int partition(int arr[], int st, int end)
{
    int pivot = arr[end], i = -1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }

    swap(arr[i + 1], arr[end]);

    return i + 1;
}

int quickSelect(int arr[], int k, int st, int end)
{
    while (st <= end)
    {
        int pivotIdx = partition(arr, st, end);

        // similar to binary search
        if (pivotIdx == k)
            return arr[pivotIdx];
        else if (pivotIdx < k) // right search
            st = pivotIdx + 1;
        else // pivotIdx > k --> left search
            end = pivotIdx - 1;
    }

    return -1; // target not found
}

int main()
{
    int n;

    cout << "Enter the size of a Array : ";
    cin >> n;
    cout << endl;

    int arr[n];

    // input the array
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    int k;

    // input k
    cout << "\nEnter the required kth index value : ";
    cin >> k;

    // valid check for k
    if (k < 1 || k > n)
    {
        cout << "Invalid input!";
        return 0;
    }

    // 1st appproach
    cout << "Kth Smallest element using sorting : " << sortSearch(arr, k, n) << endl;

    // 2nd approach
    cout << "Kth Smallest element using min Heap : " << minHeapSearch(arr, k, n) << endl;

    // 3rd approach
    // here, target is k-1
    cout << "Kth Smallest element using quick Select : " << quickSelect(arr, k - 1, 0, n - 1) << endl;

    return 0;
}