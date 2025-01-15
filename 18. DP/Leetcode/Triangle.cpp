// leetcode 120
// [[2],[3,4],[6,5,7],[4,1,8,3]]
// output: 11
// [[-1],[2,3],[1,-1,-3]]
// output: -1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Time: O(N^2), Space: O(1)
    int minimumTotal(vector<vector<int>>& arr) {
        for(int i = arr.size()-2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                arr[i][j] += min(arr[i+1][j], arr[i+1][j+1]);
            }
        }
        return arr[0][0];
    }
    // Time: O(N^2), Space: O(N)
    int fun1(vector<vector<int>>& arr) {
        vector<int> dp(arr.size()+1, 0);
        for(int i = arr.size()-1; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                dp[j] = arr[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};