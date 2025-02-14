#include <bits/stdc++.h>
using namespace std;

int BruteForce(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if(arr[i] >= x) return i;
    }
    return n;
}

int lowerbound(int arr[], int n, int x) {
    int lo = 0, hi = n-1;
    int ans = n;
    
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] >= x) {
            ans = mid;
            // look for smaller idx on the left
            hi = mid - 1;
        } else  {
            lo = mid + 1;
        }
    }
    return ans;
}

int LowerBound1(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int LowerBound(int arr[], int n, int x) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] == x) return mid - 1;
        else if(arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << arr[LowerBound(arr, n, 3)] << endl;
    cout<<*lower_bound(arr,arr+n,3)<<endl;
    return 0;
}