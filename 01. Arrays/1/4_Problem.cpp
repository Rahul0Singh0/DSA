/**
 * Find the maximum value out of all the elements in the array.
 */

#include <bits/stdc++.h>
using namespace std;

int Max(int arr[], int n) {
    int res = arr[0];
    for(int i = 1; i < n; i++) res = max(res, arr[i]);
    return res;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<Max(arr, n);
    return 0;
}