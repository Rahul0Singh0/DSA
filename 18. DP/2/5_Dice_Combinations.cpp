// https://cses.fi/problemset/task/1633
#include<iostream>
#include<vector>
#include<climits>
#define mod 1000000007
#define ll long long int
using namespace std;
vector<ll> dp(1000005,-1);
int f(int n) {
    if(n==0) return 1;
    if(dp[n] != -1) return dp[n];
    int sum = 0;
    for(int i = 1; i <= 6; i++) {
        if(n-i < 0) break;
        sum = (sum%mod + f(n-i)%mod)%mod;
    }
    return dp[n] = sum%mod;
}
int fbu(int n) {
    dp[0] = 1;
    for(int k = 1; k <= n; k++) {
        int sum = 0;
        for(int i = 1; i <= 6; i++) {
            if(k-i < 0) break;
            sum = (sum%mod + dp[k-i]%mod)%mod;
        }
        dp[k] = sum%mod;
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1000005,-1);
    cout<<fbu(n);
    return 0;
}