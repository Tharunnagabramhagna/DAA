#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/* 3. Given an array and a target value T, determine whether there are two elements whose sum is
equal to T. (Average Time Complexity should be O(n)) */

// Ans)

bool hasTwoSum(const vector<int>& arr, int target) {
    unordered_set<int> seen;

    for (int num : arr) {
        int complement = target - num;
        if (seen.find(complement) != seen.end()) {
            cout << "Pair found: (" << num << ", " << complement << ")" << endl;
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> arr = {10, 15, 3, 7};
    int target = 17;

    if (hasTwoSum(arr, target))
        cout << "Yes, two elements sum to " << target << endl;
    else
        cout << "No such pair exists." << endl;

    return 0;
}