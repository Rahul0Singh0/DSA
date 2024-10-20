// Leetcode 123
// Find the maximum profit you can achieve. You may complete at most two transactions.
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    int dp[100005][10][2];
    int f(vector<int> &prices, int i, int k, bool on) {
        if(i == prices.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = f(prices, i+1, k, on);// avoid case
        // not avoid
        if(on) {
            ans = max(ans, prices[i] + f(prices, i+1, k-1, false));
        } else {
            if(k > 0){
                ans = max(ans, f(prices, i+1, k, true) - prices[i]);
            }
        }
        return dp[i][k][on] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, 2, false);
    }
};