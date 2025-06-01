/**
 * Move all negative numbers to beginning and positive to end 
 * with constant extra space.
 */
#include <bits/stdc++.h>
using namespace std;
void fun(int arr[], int n) {
    int i = 0, j = n-1;
    while(i < j) {
        if(arr[i] < 0) i++;
        if(arr[j] > 0) j--;
        if(i > j) break;
        if(arr[i] > 0 && arr[j] < 0) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
}
int main() {
    int arr[] = {8, 3, 6, -5, -4, -2};
    int n = 6;
    fun(arr, n);
    for(int i : arr) {
        cout<<i<<" ";
    }
    return 0;
}