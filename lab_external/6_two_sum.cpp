/* 6. Given an array and a target value T, determine whether there are two elements whose
sum is equal to T. (Average Time Complexity should be O(n)) */

// Algorithm
// 1. Start.
// 2. Read the array and target value T.
// 3. Create an empty hash set.
// 4. Traverse each element in the array.
// 5. Calculate complement = T - arr[i].
// 6. Check whether the complement exists in the hash set.
// 7. If it exists, print the pair and stop.
// 8. Otherwise, insert the current element into the set.
// 9. If no pair is found, display No Pair Found.
// 10. Stop.


#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array : ";
    cin >> n;

    int nums[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i << " : ";
        cin >> nums[i];
    }

    int target;

    cout << "Enter the required target value : ";
    cin >> target;

    // T.C : O(n) ; S.C : O(n)
    unordered_set<int> s;

    for(int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if(s.count(complement)) {
            cout << "Pair found : " << complement << " and " << nums[i] << endl;
            break;
        }
        s.insert(nums[i]);
    }

    return 0;
}