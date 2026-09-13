#include <iostream>
using namespace std;

/* 1Q) Implementation of finding the maximum and minimum element using divide and conquer strategy.
Analyse and describe how the divide and conquer strategy is better when compared to traditional
approach. */

class MinMax {
public:
    int mn;
    int mx;

    MinMax(int minVal = 0, int maxVal = 0) {
        mn = minVal;
        mx = maxVal;
    }
};

class ArrayMinMax {
private:
    int *arr;
    int n;

    // Recursive helper for divide & conquer
    MinMax findMinMaxDC(int st, int end) {
        // Base case: single element
        if (st == end) {
            return MinMax(arr[st], arr[st]);
        }

        // Base case: two elements
        if (end == st + 1) {
            if (arr[st] < arr[end]) {
                return MinMax(arr[st], arr[end]);
            } else {
                return MinMax(arr[end], arr[st]);
            }
        }

        // Recursive case
        int mid = (st + end) / 2;
        MinMax left = findMinMaxDC(st, mid);
        MinMax right = findMinMaxDC(mid + 1, end);

        int mn = (left.mn < right.mn) ? left.mn : right.mn;
        int mx = (left.mx > right.mx) ? left.mx : right.mx;

        return MinMax(mn, mx);
    }

public:
    ArrayMinMax(int a[], int size) {
        arr = a;
        n = size;
    }

    // Traditional approach
    MinMax findTraditional() {
        int mn = arr[0], mx = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < mn) mn = arr[i];
            if (arr[i] > mx) mx = arr[i];
        }
        return MinMax(mn, mx);
    }

    // Divide and conquer approach
    MinMax findDivideConquer() {
        return findMinMaxDC(0, n - 1);
    }
};

int main() {
    int arr[] = {5, 2, 9, 1, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    ArrayMinMax obj(arr, n);

    MinMax t = obj.findTraditional();
    cout << "Traditional -> Min = " << t.mn << ", Max = " << t.mx << endl;

    MinMax d = obj.findDivideConquer();
    cout << "Divide & Conquer -> Min = " << d.mn << ", Max = " << d.mx << endl;

    return 0;
}
