#include<iostream>
#include<algorithm>
using namespace std;
void InsertionSort(int A[], int n) {
    int i, j, p;
    for(int i = 1; i < n; i++) { // no. of passes
        int p = A[i];
        j = i-1;
        while(j > -1 && A[j] > p) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = p;
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
    InsertionSort(A, n);
    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
}