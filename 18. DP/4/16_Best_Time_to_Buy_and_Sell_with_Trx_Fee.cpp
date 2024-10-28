#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    int dp[50005][2];
    int fe;
    int f(vector<int>& p, int i, bool on) {
        if(i == p.size()) return 0;
        if(dp[i][on] != -1) return dp[i][on];
        int ans = INT_MIN;
        ans = f(p, i+1, on); //avoid case
        // not avoid
        if(on) { //true = sell it
            ans = max(ans, (p[i]-fe)+f(p, i+1, false));
        } else { // false = buy it
            ans = max(ans, f(p, i+1, true) - p[i]);
        }
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        fe = fee;
        memset(dp, -1, sizeof dp);
        return f(prices, 0, false);
    }
};