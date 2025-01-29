// Calculate the number of ways in which a person can climb n stairs if he can take exactly 1, 2 or 3
// steps at each level.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int dp[1000] = {0};
    function<int(int)> stair = [&](int n) {
        if(n == 1 || n == 2 || n == 3) return n;
        if(dp[n]) return dp[n];
        return dp[n] = stair(n-1) + stair(n-2);
    };
    cout<<stair(n);
    return 0;
}