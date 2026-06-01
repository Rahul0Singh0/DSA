// Multiplication of two matrices
#include <bits/stdc++.h>
using namespace std;
void input(int **arr, int n, int m) {
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin>>arr[i][j];
        }
    }
}
void output(int **arr, int n, int m) {
    cout<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void deallocate(int **arr, int n) {
    for(int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
void multiplcation(int **a, int **b, int n1, int m1, int n2, int m2) {
    int **res = new int*[n1];
    for(int i = 0; i < n1; i++) {
        res[i] = new int[m2];
        for(int j = 0; j < m2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < n1; k++) {
                res[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    output(res, n1, m2);
    deallocate(res, n1);
}

int main() {
    int n1, m1;
    cin>>n1>>m1;
    int **a = new int*[n1];
    input(a, n1, m1);
    int n2, m2;
    cin>>n2>>m2;
    int **b = new int*[n2];
    input(b, n2, m2);
    if(n2 != m1) {
        cout<<"Multiplication is not possible between given matrices"<<endl;
        return 0;
    }
    multiplcation(a, b, n1, m1, n2, m2);
    // deallocating memory
    deallocate(a, n1);
    deallocate(b, n2);
    return 0;
}