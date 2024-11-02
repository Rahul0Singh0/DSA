#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[505][505];
    int f(string &s1, string &s2, int i, int j) {
        if(s1.size() == i) return s2.size()-j;
        if(s2.size() == j) return s1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = f(s1,s2,i+1,j+1);
        return dp[i][j] = min({1+f(s1,s2,i+1,j+1), 1+f(s1,s2,i+1,j), 1+f(s1,s2,i,j+1)});
    }
    int minDistance(string word1, string word2) {
        memset(dp,0,sizeof(dp));
        int n = word1.size();
        int m = word2.size();
        // base case
        for(int j = 0; j < m; j++) {
            int i = n;
            dp[i][j] = m-j;
        }
        for(int i = 0; i < n; i++) {
            int j = m;
            dp[i][j] = n-i;
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(word1[i] == word2[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min({1+dp[i+1][j+1], 1+dp[i+1][j], 1+dp[i][j+1]});
            }
        }
        return dp[0][0];
    }
};