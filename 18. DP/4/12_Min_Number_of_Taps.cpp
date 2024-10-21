// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
// Leetcode 1326
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            int ans = INT_MAX;
            for(int j = start; j <= end; j++) {
                // +1 // ith->top
                // dp[end] = min(dp[end], dp[j] + 1); 
                ans = min(ans, dp[j]);
            }
            if(ans != INT_MAX) {
                dp[end] = min(dp[end], ans+1);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};