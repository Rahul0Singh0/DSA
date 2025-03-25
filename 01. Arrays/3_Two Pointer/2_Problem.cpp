// Sort the array of 0's and 1's. without using built in method
#include <bits/stdc++.h>
using namespace std;
void sort01(int arr[], int n) {
    int noo = 0, noz = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) noz++;
        else noo++;
    }
    for(int i = 0; i < n; i++) {
        if(i < noz) arr[i] = 0;
        else arr[i] = 1;
    }
}
// Two Pointer
void sortAgain(int arr[], int n) {
    int i = 0, j = n-1;
    while(i < j) {
        if(arr[i] == 0) i++;
        if(arr[j] == 1) j--;
        if(i > j) break;
        if(arr[i] == 1 && arr[j] == 0) {
            arr[i] = 0;
            arr[j] = 1;
            i++;
            j--;
        }
    }
}
int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 0, 1};
    int n = 8;
    sortAgain(arr, n);
    for(int i : arr) {
        cout<<i<<" ";
    }
    return 0;
}