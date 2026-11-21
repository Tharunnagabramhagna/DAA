// 11. Divide and conquer: Implementation of maximum-subarray problem.

// Algorithm
// 1. Start.
// 2. Read the array elements.
// 3. Divide the array into two halves.
// 4. Find the maximum subarray sum in the left half.
// 5. Find the maximum subarray sum in the right half.
// 6. Find the maximum subarray sum crossing the middle.
// 7. Compare the three sums.
// 8. Return the largest sum.
// 9. Display the maximum subarray sum.
// 10. Stop.

// Test Case : arr = [5,4,-1,7,8] --> output : 23
// T.C : O(n log n) ; S.C : O(log n)

#include <iostream>
#include <climits>
using namespace std;

int maxCrossingSum(int arr[], int st, int mid, int end)
{
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN;

    // left half Sum
    for (int i = mid; i >= st; i--)
    {
        sum += arr[i];
        leftSum = max(sum, leftSum);
    }

    sum = 0;

    // right half Sum
    for (int i = mid + 1; i <= end; i++)
    {
        sum += arr[i];
        rightSum = max(sum, rightSum);
    }

    return leftSum + rightSum; // totalSum
}

int MaximumSum(int arr[], int st, int end)
{
    if (st == end)
        return arr[st];

    int mid = st + (end - st) / 2;

    int left = MaximumSum(arr, st, mid);
    int right = MaximumSum(arr, mid + 1, end);
    int cross = maxCrossingSum(arr, st, mid, end);

    return max(left, max(right, cross));
}

int main()
{
    int n;

    cout << "Enter the size of array : ";
    cin >> n;
    cout << endl;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    cout << "Maximum Subarray Sum (Divide and Conquer) : " << MaximumSum(arr, 0, n - 1) << endl;

    return 0;
}