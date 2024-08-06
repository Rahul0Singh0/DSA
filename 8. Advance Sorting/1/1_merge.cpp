// Merging two sorted array
#include<iostream>
using namespace std;
int main() {
    int arr1[5] = {3,4,6,8,20};
    int arr2[7] = {1,2,5,7,9,10,12};
    int n = 5, m = 7;
    int i = 0, j = 0;
    int arr3[n+m], k = 0;
    while(i < 5 && j < 7) {
        if(arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }
    while(i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while(j < m) {
        arr3[k++] =arr2[j++];
    }
    for(int i = 0; i < n+m; i++) {
        cout<<arr3[i]<<" ";
    }

    return 0;
}