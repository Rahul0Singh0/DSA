// https://www.geeksforgeeks.org/problems/shortest-uncommon-subsequence5746/1
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int dp[501][501];
    int f(string &s, string &t, int i, int j) {
        if(i < 0) return 1000;
        if(j < 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int k = j;
        while(k >= 0) {
            if(t[k] == s[i]) break;
            k--;
        }
        if(k < 0) return 1; //this char not present in t
        return dp[i][j] = min(f(s,t,i-1,j), 1+f(s,t,i-1, k-1));
    }
    int shortestUnSub(string S, string T) {
        // code here
        memset(dp, -1, sizeof dp);
        int ans = f(S, T, S.size()-1, T.size()-1);
        if(ans >= 1000) return -1;
        return ans;
    }
};