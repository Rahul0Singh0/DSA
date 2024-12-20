#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double dp[30][30][105];
    double dx[8] = {1, 2, -1, -2, 1, 2, -1, -2};
    double dy[8] = {2, 1, 2, 1, -2, -1, -2, -1};
    double f(int n, int i, int j, int k) {
        if(i < 0 or j < 0 or i >= n or j >= n) return 0;
        if(k == 0) return 1;
        if(dp[i][j][k] > -0.9) return dp[i][j][k];
        double ans = 0.0;
        ans += f(n, i+1, j+2, k-1) * (0.125);
        ans += f(n, i+2, j+1, k-1) * (0.125);
        ans += f(n, i-1, j+2, k-1) * (0.125);
        ans += f(n, i-2, j+1, k-1) * (0.125);
        ans += f(n, i+1, j-2, k-1) * (0.125);
        ans += f(n, i+2, j-1, k-1) * (0.125);
        ans += f(n, i-1, j-2, k-1) * (0.125);
        ans += f(n, i-2, j-1, k-1) * (0.125);
        // for(int m = 0; m < 8; m++) {
        //     ans += f(n, i+dx[m], j+dy[m], k-1) * (0.125);
        // }
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int r, int c) {
        memset(dp, -1, sizeof dp);
        return f(n, r, c, k);
    }
};

int main() {
    // example : input: 3 2 0 0 , Output: 0.06250
    int n, k, r, c;
    cin>>n>>k>>r>>c;
    Solution s;
    cout<<s.knightProbability(n,k,r,c);
    return 0;
}