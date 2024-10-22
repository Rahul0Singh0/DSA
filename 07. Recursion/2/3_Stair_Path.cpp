/**
 * n = 4, ans = 5;
 * n = 7, ans = 21
 */
#include <iostream>
#include <cstring>
using namespace std;
int dp[10005];
// Repeated Subproblem so apply dp
int f(int n) {
    if(n == 1 or n == 2 or n == 3) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1) + f(n-2);
}
int main() {
    int n;
    cin>>n;
    // memset(dp, -1, sizeof dp);
    // cout<<f(n)<<"\n";
    memset(dp, 0, sizeof dp);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<dp[n]<<"\n";
    return 0;
}