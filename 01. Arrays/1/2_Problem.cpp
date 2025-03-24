/**
 * Calculate sum of all numbers in the given array
 */

#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int n) {
    int res = 0;
    for(int i = 0; i < n; i++) res += arr[i];
    return res;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<sum(arr, n);
    return 0;
}