// Leetcode 122
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[30005][2];
    int f(vector<int>& p, int i, bool on) {
        if(i == p.size()) return 0;
        if(dp[i][on] != -1) return dp[i][on];
        int ans = INT_MIN;
        ans = f(p, i+1, on); //avoid case
        // not avoid
        if(on) { //true = sell it
            ans = max(ans, p[i]+f(p, i+1, false));
        } else { // false = buy it
            ans = max(ans, f(p, i+1, true) - p[i]);
        }
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof dp);
        return f(prices, 0, false);
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    Solution s;
    cout<<"\n"<<s.maxProfit(v);
    return 0;
}