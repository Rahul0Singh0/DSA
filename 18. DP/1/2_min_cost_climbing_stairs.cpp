// leetcode 746
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int fun(vector<int>& cost, int idx, int sum) {
    //     if(idx >= cost.size()) return sum;
    //     return min(fun(cost, idx+1, sum+cost[idx]), fun(cost, idx+2, sum+cost[idx]));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     return min(fun(cost, 0, 0), fun(cost, 1, 0));
    // }
    // int fun(vector<int>& cost, int idx, vector<int>& dp) {
    //     if(idx == 0 or idx == 1) return cost[idx];
    //     if(dp[idx] != -1) return dp[idx];
    //     return dp[idx] = cost[idx] + min(fun(cost, idx-1, dp), fun(cost, idx-2, dp));
    // }
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n, -1);
    //     // top to down (Memoization)
    //     return min(fun(cost, n-1, dp), fun(cost, n-2, dp));
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // bottom to up [Tabulation]
        for(int i = 2; i < n; i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};
int main() {

}