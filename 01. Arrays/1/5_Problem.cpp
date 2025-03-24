/**
 * Find the second larget element in the given array.
 */

#include <bits/stdc++.h>
using namespace std;

int sec_largest(int arr[], int n) {
    int largest = INT_MIN, second_largest = INT_MIN;
    for(int i = 0; i < n; i++) largest = max(largest, arr[i]);
    for(int i = 0; i < n; i++) {
        if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    return second_largest == INT_MIN ? -1 : second_largest;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<sec_largest(arr, n);
    return 0;
}