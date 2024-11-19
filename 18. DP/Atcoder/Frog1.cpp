// https://atcoder.jp/contests/dp/tasks/dp_a
// Either one or two jump at a time
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int dp[100005];
int f(int h[], int i) {
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    ans = min(ans, abs(h[i]-h[i-1]) + f(h, i-1));
    if(i > 1) ans = min(ans, abs(h[i]-h[i-2]) + f(h, i-2));
    return dp[i] = ans;
}
int main() {
    int n;
    cin>>n;
    int h[n];
    for(int i = 0; i < n; i++) cin>>h[i];
    memset(dp, -1, sizeof dp);
    cout<<f(h, n-1);
    return 0;
}