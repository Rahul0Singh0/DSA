// Count Sort
#include<iostream>
using namespace std;
int findMax(int A[], int n) {
    int m = A[0];
    for(int i = 1; i < n; i++) {
        if(A[i] > m) m = A[i];
    }
    return m;
}
int main() {
    int A[] = {6,3,9,10,15,6,8,12,3,6};
    int n = sizeof(A)/sizeof(A[0]);
    int m = findMax(A, n);
    // int count[m+1] = {0};
    // int *count = (int*)malloc(sizeof(int)*(m+1));
    int *count = new int[m+1];
    for(int i = 0; i <= m; i++) {
        count[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        count[A[i]]++;
    }
    int i = 0, j = 0;
    while(j < m+1) {
        if(count[j]) {
            A[i++] = j;
            count[j]--;
        }
        else j++;
    }
    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
}