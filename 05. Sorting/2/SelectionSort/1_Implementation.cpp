#include<iostream>
#include<algorithm>
using namespace std;
void SelectionSort(int A[], int n) {
    int i, j, k;
    for(int i = 0; i < n-1; i++) { // no. of passes
        for(int j = k = i; j < n; j++) {
            if(A[j] < A[k]) k = j;
        }
        swap(A[i], A[k]); // swap find the smallest element to selected position
    }
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++) {
        int e;
        cin>>e;
        A[i] = e;
    }
    SelectionSort(A, n);
    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
}