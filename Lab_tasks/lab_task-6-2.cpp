#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

/* 2Q) Divide and conquer: Implementation of maximum-subarray problem. */

class MaxSubarray
{
    vector<int> arr;

    int maxCrossingSum(int l, int m, int r)
    {
        int sum = 0, leftSum = INT_MIN;
        for (int i = m; i >= l; i--)
        {
            sum += arr[i];
            leftSum = max(leftSum, sum);
        }

        sum = 0;
        int rightSum = INT_MIN;
        for (int i = m + 1; i <= r; i++)
        {
            sum += arr[i];
            rightSum = max(rightSum, sum);
        }

        return leftSum + rightSum;
    }

    int maxSubarrayDC(int l, int r)
    {
        if (l == r)
            return arr[l];
        int m = (l + r) / 2;
        return max({maxSubarrayDC(l, m), maxSubarrayDC(m + 1, r), maxCrossingSum(l, m, r)});
    }

public:
    MaxSubarray(const vector<int> &a) : arr(a) {}
    int findMaxSubarray() { 
        return maxSubarrayDC(0, arr.size() - 1);
    }
};

int main()
{
    vector<int> arr = {2, -4, 3, -1, 2, -4, 6, -1};
    MaxSubarray obj(arr);
    cout << "Maximum Subarray Sum = " << obj.findMaxSubarray() << endl;
    return 0;
}
