// Leetcode 75
/**
 * Sort the array of 0's, 1's, and 2's
 */

#include <bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n) {
    int no1 = 0, no0 = 0, no2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) no0++;
        else if(arr[i] == 1) no1++;
        else no2++;
    }
    for(int i = 0; i < n; i++) {
        if(i < no0) arr[i] = 0;
        else if(i < (no0+no1)) arr[i] = 1;
        else arr[i] = 2;
    }
}

// 3 Pointer
void sortAgain(int arr[], int n) {
    
}

int main() {
    int arr[] = {1, 2, 0, 0, 2, 1, 0};
    int n = 7;
    sortAgain(arr, n);
    for(int i: arr) {
        cout<<i<<" ";
    }
    return 0;
}