// Leetcode 198
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int fun(vector<int> arr, int idx) {
        if(idx == arr.size()-1) return arr[idx]; // single house
        if(idx == arr.size()-2) return max(arr[idx], arr[idx+1]); // two house
        return max(arr[idx]+fun(arr, idx+2), 0+fun(arr, idx+1));
    }
    // Memoization (TOP DOWN APPROACH)
    int funTopDown(vector<int> arr, int idx) {
        if(idx == arr.size()-1) return arr[idx]; // single house
        if(idx == arr.size()-2) return max(arr[idx], arr[idx+1]); // two house
        if(dp[idx] != -1) return dp[idx]; // ith state already computed
        // if dp[idx] was -1 so lets compute ith state for the first
        return max(arr[idx]+fun(arr, idx+2), 0+fun(arr, idx+1));
    }
    // Tabulation (bottom up approach)
    int funBottomUp(vector<int> arr, int idx) {
        int n = arr.size();
        if(n == 1) return arr[0];
        dp.clear();
        dp.resize(n);
        dp[n-1] = arr[n-1];
        dp[n-2] = max(arr[n-1], arr[n-2]);
        for(int i = n-3; i >= 0; i--) {
            dp[i] = max(arr[i]+dp[i+2], 0+dp[i+1]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        dp.clear();
        // dp.resize(nums.size(), -1);
        dp.resize(101, -1);
        return funBottomUp(nums, 0);
    }
};
