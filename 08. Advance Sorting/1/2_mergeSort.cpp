#include<iostream>
using namespace std;
void Merge(int *arr, int l, int mid, int h) {
    int ar[h+1];
    int i = l, j = mid+1, k = l;
    while(i <= mid && j <= h) {
        if(arr[i] < arr[j]) ar[k++] = arr[i++];
        else ar[k++] = arr[j++];
    }
    while(i <= mid) ar[k++] = arr[i++];
    while(j <= h) ar[k++] = arr[j++];
    for(int i = l; i <= h; i++) arr[i] = ar[i];
}
// Iterative method
void mergeSort(int *arr, int n) {
    int p, i, l, mid, h;
    for(p = 2; p <= n; p = p*2) {
        for(i = 0; i+p-1 < n; i = i+p) {
            l = i; h = i+p-1; mid = l+(h-l)/2;
            Merge(arr, l, mid, h);
        }
    }
    if(p/2 < n) Merge(arr, 0, p/2-1, n-1);
}
// Recursion based
void mergeSort1(int arr[], int l, int h) {
    if(l < h) {
        int mid = (l+h)/2;
        mergeSort1(arr, l, mid);
        mergeSort1(arr, mid+1, h);
        Merge(arr, l, mid, h);
    }
}
int main() {
    int arr[] = {4,1,3,9,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
}