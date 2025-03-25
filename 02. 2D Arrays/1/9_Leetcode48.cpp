/**
 * Rotate the matrix by 90 degree clockwise
 * [1,2,3]      [7,4,1]
 * [4,5,6]  =>  [8,5,2]
 * [7,8,9]      [9,6,3]
 * 
 * Step 1: Transpose
 * Step 2: Each row reverse
 */
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

void rotate(Vector& arr) {
    transpose(arr);
    for(int i = 0; i < arr.size(); i++) {
        reverse(arr[i].begin(), arr[i].end());
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
    rotate(v);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}