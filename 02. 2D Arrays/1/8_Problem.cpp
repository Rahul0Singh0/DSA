// You are given a matrix of size NxN.
// Change this matrix into its transpose without using extra space
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Vector;

void transpose(Vector& arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) break;
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main() {
    int n;
    cin>>n;
    Vector v(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>v[i][j];
        }
    }
    transpose(v);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}