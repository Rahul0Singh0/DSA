/**
 * Find out the given element 'x' from the array.
 */

#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int target, int n) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    int target;
    cin>>target;
    cout<<find(arr, target, n);
    return 0;
}