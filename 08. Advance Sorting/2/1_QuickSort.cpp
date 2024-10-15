// Quick Sort -> select pivot element then find out that correct position(partitioning position)
#include<iostream>
#include<algorithm>
using namespace std;
int Partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l, j = h;
    do {
        do {i++;} while(A[i] <= pivot);
        do {j--;} while(A[j] > pivot);
        if(i < j) swap(A[i], A[j]); // interchange their position
    }while(i < j);
    swap(A[l], A[j]); // swap pivot element with their correct index
    return j; // return partitioning point(index)

}
void QuickSort(int A[], int l, int h) {
    if(l < h) { // elements are present in given list
        int j = Partition(A, l, h);
        QuickSort(A, l, j); // Left side
        QuickSort(A, j+1, h); // Right side
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
    QuickSort(A, 0, n);
    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
}