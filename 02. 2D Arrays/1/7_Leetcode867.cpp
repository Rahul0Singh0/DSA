#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> Vector;

Vector fun(Vector& arr) {
    int n = arr.size();
    int m = arr[0].size();
    Vector res(m, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res[j][i] = arr[i][j];
        }
    }
    return res;
}

int main() {
    int n, m;
    cin>>n>>m;
    Vector v(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>v[i][j];
        }
    }
    Vector res = fun(v);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}