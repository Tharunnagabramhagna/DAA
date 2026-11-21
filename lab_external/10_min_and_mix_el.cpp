/* 10. Implementation of finding the maximum and minimum element using divide and
conquer strategy. Analyse and describe how the divide and conquer strategy is better
when compared to traditional approach. */

// Algorithm
// 1. Start.
// 2. Read the array elements.
// 3. If there is one element, return it as both minimum and maximum.
// 4. If there are two elements, compare and return the smaller and larger elements.
// 5. Otherwise, divide the array into two halves.
// 6. Find the minimum and maximum of both halves recursively.
// 7. Compare the two minimum values and the two maximum values.
// 8. Return the final minimum and maximum.
// 9. Display the results.
// 10. Stop.

#include <iostream>
using namespace std;

pair<int,int> findMinMax(int arr[], int st, int end) {
    // Base Case-1 (only one element)
    if(st == end) 
        return {arr[st], arr[end]};
    
    // Base Case-2 (only two elements)
    if(st == end + 1) {
        if(arr[st] <= arr[end + 1])
            return {arr[st], arr[end + 1]};
        else
            return {arr[end + 1], arr[st]};
    }

    int mid = st + (end - st) / 2;

    pair<int,int> left = findMinMax(arr, st, mid); // left half recursive case
    pair<int,int> right = findMinMax(arr, mid + 1, end); // right half recursive case

    // min and max among 2 halfs
    int Min = min(left.first, right.first); 
    int Max = max(left.second, right.second);
    
    return {Min, Max};
}

int main() {
    int n;

    cout << "Enter the size of the array : ";
    cin >> n;
    cout << endl;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter the element at index " << i << " : ";
        cin >> arr[i];
    }

    pair<int,int> ans = findMinMax(arr, 0, n-1);

    cout << "\nMinimum and Maximum Elements of array (Divider and Conquer) : ";
    cout << "\nMinimum Element : " << ans.first << endl;
    cout << "Maximum Element : " << ans.second << endl;

    return 0;
}