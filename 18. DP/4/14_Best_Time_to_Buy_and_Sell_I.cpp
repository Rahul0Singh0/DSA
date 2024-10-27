// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = INT_MIN;
        int b = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            b = min(b, prices[i]);
            for(int j = i+1; j < prices.size(); j++) {
                a = max(a, prices[j]-b);
            }
        }
        return a < 0 ? 0 : a;
    }
    // achieving the time in O(N)
    int f(vector<int>& p) {
        int a = INT_MIN;
        int b = INT_MAX;
        for(int i = 0; i < p.size(); i++) {
            b = min(b, p[i]);
            a = max(a, p[i]-b);
        }
        return a < 0 ? 0 : a;
    }
};
int main() {
    int n; cin>>n;
    vector<int> v(n);
    for(int i =0; i < n; i++) cin>>v[i];
    Solution s;
    cout<<"\n"<<s.maxProfit(v);
    return 0;
}