#include <iostream>
#include <vector>
using namespace std;

void linearSearch(vector<int>& arr,int target) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == target) {
            cout << "Target is found at index " << i << endl;
            return;
        }
    }
    cout << "Target not found." << endl;
}

bool isSorted(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

void binarySearch(vector<int>& arr,int target) {
    int st = 0, end = arr.size() - 1;
    
    while(st <= end) {
        int mid = st + (end - st) / 2;
        if(arr[mid] == target) {
            cout << "Target found at index " << mid << endl;
            return;
        } else if(arr[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    printf("Target not found.");
}

int main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    
    if(n <= 1)
        return 0;

    vector<int>arr(n, 0);
    
    for(int i = 0; i < n; i++) {
        cout << "Enter" << i << "index element : ";
        cin >> arr[i];
    }
    
    int target;
    
    cout << "Enter the target value : ";
    cin >> target;
    
    cout << endl;

    // 1Q) Linear Search
    
    linearSearch(arr,target);
    
    cout << endl;
    
    // 2Q) Binary Search
    
    if(isSorted(arr))
        binarySearch(arr,target);
    else
        printf("The array is not sorted for Binary Search.");  
    
    return 0;
}