#include <iostream>
#include <climits>
using namespace std;

/* 2Q) Divide and conquer: Implementation of maximum-subarray problem. */

class MaxSubarray {
private:
    int *arr;
    int n;

    // Helper to find max crossing sum
    int maxCrossingSum(int l, int m, int r) {
        int sum = 0;
        int leftSum = INT_MIN;

        // Include elements on left of mid
        for (int i = m; i >= l; i--) {
            sum += arr[i];
            if (sum > leftSum) leftSum = sum;
        }

        sum = 0;
        int rightSum = INT_MIN;

        // Include elements on right of mid
        for (int i = m + 1; i <= r; i++) {
            sum += arr[i];
            if (sum > rightSum) rightSum = sum;
        }

        return leftSum + rightSum;
    }

    // Recursive divide and conquer
    int maxSubarrayDC(int l, int r) {
        if (l == r) return arr[l]; // base case

        int m = (l + r) / 2;

        int leftMax = maxSubarrayDC(l, m);
        int rightMax = maxSubarrayDC(m + 1, r);
        int crossMax = maxCrossingSum(l, m, r);

        return max(leftMax, max(rightMax, crossMax));
    }

public:
    MaxSubarray(int a[], int size) {
        arr = a;
        n = size;
    }

    int findMaxSubarray() {
        return maxSubarrayDC(0, n - 1);
    }
};

int main() {
    int arr[] = {2, -4, 3, -1, 2, -4, 6, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    MaxSubarray obj(arr, n);
    cout << "Maximum Subarray Sum = " << obj.findMaxSubarray() << endl;

    return 0;
}
