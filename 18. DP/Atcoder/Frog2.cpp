// https://atcoder.jp/contests/dp/tasks/dp_b
// Upto kth jumps
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int dp[100005];
int f(int h[], int i, int k) {
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++) {
        if(i-j >= 0) ans = min(ans, abs(h[i]-h[i-j]) + f(h, i-j, k));
    }
    return dp[i] = ans;
}
int main() {
    int n, k;
    cin>>n>>k;
    int h[n];
    for(int i = 0; i < n; i++) cin>>h[i];
    memset(dp, -1, sizeof dp);
    cout<<f(h, n-1, k);
    return 0;
}