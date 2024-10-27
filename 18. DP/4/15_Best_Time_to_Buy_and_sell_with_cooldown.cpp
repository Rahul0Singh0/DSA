#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {  
public:
    int dp[5005][2][2];
    int f(vector<int>& p, int i, bool on, bool cool) {
        if(i == p.size()) return 0;
        if(dp[i][on][cool] != -1) return dp[i][on][cool];
        int ans = 0;
        ans = f(p, i+1, on, cool);
        if(cool) {
            ans = f(p, i+1, on, !cool);
        } else {
            if(on) { // sell it
                ans = max(ans, p[i] + f(p, i+1, !on, !cool));
            } else { // buy
                ans = max(ans, f(p, i+1, !on, cool) - p[i]);
            }
        }
        return dp[i][on][cool] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, false, false);
    }
};