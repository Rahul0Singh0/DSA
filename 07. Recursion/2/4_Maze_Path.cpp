/**
 * Given 2d array matrix, a person located at A[0][0] try to reach at A[n-1][m-1]
 * return how many ways to reach that destination point
 * Example: n = 3, m = 3, Ouput: 6 
 *         RRDD, RDRD, RDDR
 *         DRRD, DRDR, DDRR
 */
#include <iostream>
#include <cstring>
using namespace std;
int dp[1005][1005];
int f(int i, int j, int n, int m) {
    if(i < 0 or j < 0 or i > n or j > m) return 0;
    if(i == n and j == m) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = f(i+1, j, n, m) + f(i, j+1, n, m);
}
int main() {
    int n,m;
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout<<f(0,0,n-1,m-1);
    return 0;
}