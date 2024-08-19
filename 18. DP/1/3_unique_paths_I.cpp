#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    // Tabulation bottom to up
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        for(int i = 0; i < m; i++) {
            for(int  j = 0 ; j < n; j++) {
                if(i ==0 or j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    // Memoization top down approach
    int fun(int m, int n, vector<vector<int>>& dp) {
        if(m == 1 && n == 1) return 1;
        if(m == 0 || n == 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = fun(m-1, n, dp)+fun(m, n-1, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        return fun(m,n,dp);
    }
    // Precise code
    int uniquePaths(int m, int n) {
        if(m == 1 and n == 1) return 1;
        if(m == 0 or n == 0) return 0;
        return uniquePaths(m-1, n)+uniquePaths(m, n-1);
    }
};