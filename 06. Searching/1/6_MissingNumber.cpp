/**
 * Given a sorted array of non-negative distinct integers, find the
 * smallest missing non-negative element in it.
 */
#include <bits/stdc++.h>
using namespace std;
int f(int arr[], int n) {
    int lo = 0, hi = n-1;
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == mid) lo = mid + 1;
        else {
            ans = mid;
            hi = mid - 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {0, 1, 2, 3, 4, 8, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    for(int i = 0; i < n; i++) {
        if(i != arr[i]) {
            cout<<i<<endl;
            break;
        }
    }
    cout<<f(arr, n)<<endl;
    return 0;
}