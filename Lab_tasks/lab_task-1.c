#include <stdio.h>
#include <stdbool.h>

void linearSearch(int arr[], int size,int target) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == target) {
            printf("Target is found at %d index.",i);
            return;
        }
    }
    printf("Target not found.");
}

bool isSorted(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}

void binarySearch(int arr[], int size,int target) {
    int st = 0, end = size - 1;
    
    while(st <= end) {
        int mid = st + (end - st) / 2;
        if(arr[mid] == target) {
            printf("Target found at %d index.",mid);
            return;
        } else if(arr[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    printf("Target not found.");
}

void main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    
    if(n <= 1)
        return;
    
    int arr[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter %d index element : ",i);
        scanf("%d",&arr[i]);
    }
    
    int target;
    
    printf("Enter the target value : ");
    scanf("%d",&target);
    
    linearSearch(arr,n,target);

    printf("\n");

    if(isSorted(arr,n))
        binarySearch(arr,n,target);
    else
        printf("The array is not sorted for Binary Search.");   
}