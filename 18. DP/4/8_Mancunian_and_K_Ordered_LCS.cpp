// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
#include <iostream>
#include <cstring>
#define ll long long int
using namespace std;

ll dp[2001][2001][6];

ll f(int a[], int b[], int n, int m, int i, int j, int k) {
    if(n == i or m == j) return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    ll res = 0;
    if(a[i] == b[j]) res = 1+f(a,b,n,m,i+1,j+1,k);
    else if(k > 0) {
        res = max(1+f(a,b,n,m,i+1,j+1,k-1), max(f(a,b,n,m,i+1,j,k), f(a,b,n,m,i,j+1,k)));
    }
    else {
        res = max(res, max(f(a,b,n,m,i+1,j,k), f(a,b,n,m,i,j+1,k)));
    }
    // else {
    //     if(k > 0) res = 1+f(a,b,n,m,i+1,j+1,k-1);
    //     res = max(res, f(a,b,n,m,i+1,j,k));
    //     res = max(res, f(a,b,n,m,i,j+1,k));
    // }
    return dp[i][j][k] = res;
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    memset(dp, -1, sizeof dp);
    cout<<f(a, b, n, m, 0, 0, k);
    return 0;
}