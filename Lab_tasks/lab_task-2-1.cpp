#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/* Question-1 : Programs for summation of series 1+X+X^2+X^3+…with different time
complexities.*/


// Method-1)

double sumGeoSeries1(double a, double r, double n) {
    if(r == 1)
        return n * a;
    else
        return (a * (1 - pow(r,n))) / (1 - r);
}

// Method-2)

double sumGeoSeries2(double a, double r, double n) {
    if(r == 1)
        return n * a;
    else {
        double sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a;
            a *= r;
        }
        return sum;
    }
}

int main() {
    double a,r,n;
    
    cout << "Enter first term of progression : ";
    cin >> a;
    
    cout << "Enter the common ratio : ";
    cin >> r;
    
    cout << "Enter the number of terms : ";
    cin >> n;
    
    cout << endl;

    cout << "Method-1" << endl;
    cout << "Sum of Geometric Series : " << sumGeoSeries1(a,r,n); // O(1)
    cout << endl;

    cout << "Method-2" << endl;
    cout << "Sum of Geometric Series : " << sumGeoSeries2(a,r,n); // O(n)
    cout << endl;

    /* Question-2) Write a program to find the Kth smallest element in the array. */

    int size;
    
    cout << "Enter the size of the array : ";
    cin >> size;
    
    vector<int>arr(size);
    
    for(int i = 0; i < size; i++) {
        cout << "Enter " << i << " index element : ";
        cin >> arr[i];
    }
    
    // Step-1 : Sort the array
    sort(arr.begin(), arr.end());
    
    int k;
    
    cout << "Enter the value of k : ";
    cin >> k;
    
    if(k < 1 || k > size) {
        cout << "Invalid K";
        return 0;
    }
    
    // Step-2 : Find the Kth Smallest element
    cout << "\nKth Smallest element : " << arr[k-1] << endl;
       
    return 0;
}