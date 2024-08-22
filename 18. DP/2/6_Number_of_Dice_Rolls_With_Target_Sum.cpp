// leetcode 1155
#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;
class Solution {
public:
// TIme : O(N∗K∗T)
// Space : O(N*T)
    vector<vector<int>> dp;
    int f(int n, int k, int t) {
        if(n == 0 && t == 0) return 1; 
        if(n == 0) return 0;
        if(dp[n][t] != -1) {
            return dp[n][t];
        }
        int sum = 0;
        for(int v = 1; v <= k; v++) {
            if(t-v < 0) continue;
            sum = ((sum%mod) + f(n-1, k, t-v)%mod)%mod;
        }
        return dp[n][t] = sum%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.clear();
        dp.resize(35, vector<int>(1005, -1));
        return f(n, k, target);
    }
};