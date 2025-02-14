#include <bits/stdc++.h>
using namespace std;

// Bruteforce
int UpperBound(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] > x) {
            return i;
        }
    }
    return n;
}

int upperbound(int arr[], int n, int x) {
    int lo = 0, hi = n-1;
    int ans = n; 
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] > x) {
            ans = mid;
            // look for smaller index on the left;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << arr[UpperBound(arr, n, 3)] << endl;
    cout << arr[upperbound(arr, n, 3)] << endl; 
    cout<<*upper_bound(arr, arr+n, 3)<<endl;
    return 0;
}