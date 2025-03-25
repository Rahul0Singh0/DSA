// Rotate the given array by k steps, where k is non-negative
#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n, int k) {
    k = k % n;
    // Bruteforce : Time: O(K*N)
    // while(k--) {
    //     int temp = arr[n-1];
    //     for(int i = n-2; i >= 0; i--) {
    //         arr[i+1] = arr[i];
    //     }
    //     arr[0] = temp;
    // }
    
    // Reverse method
    reverse(arr, arr+(n-k));
    reverse(arr+n-k, arr+n);
    reverse(arr, arr+n);
}

int main() {
    int arr[] = {1,6,2,3,7,4};
    int k = 8;
    int n = 6;
    rotate(arr, n, k);
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    return 0;
}