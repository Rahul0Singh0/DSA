#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursion
// int f(int i, int j, vector<int> &arr) {
//     if(i == j or i+1 == j) return 0;
//     int ans = INT_MAX;
//     for(int k = i+1; k < j; k++) {
//         ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i]*arr[k]*arr[j]);
//     }
//     return ans;
// }

// DP with Memo (top down)
vector<vector<int>> dp;
int f(int i, int j, vector<int> &arr) {
    if(i == j or i+1 == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k = i+1; k < j; k++) {
        ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i]*arr[k]*arr[j]);
    }
    return dp[i][j] = ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    dp.clear();
    dp.resize(1005, vector<int> (1000, -1));
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    // DP with Tabulation (Bottom up)
    // Focus on Ordering
    for(int len = 3; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i+1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
            }
        }
    }

    // cout<<f(0, n-1, v)<<"\n";
    cout<<dp[0][n-1]<<"\n";
    return 0;
}