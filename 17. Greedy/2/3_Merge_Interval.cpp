// Leetcode 56
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // sorting base on ending time
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[n-1]);
        for(int i = n-2; i >= 0; i--) {
            vector<int> curr = intervals[i];
            if(curr[1] >= result[result.size()-1][0]) {
                result[result.size()-1][0] = min(result[result.size()-1][0], curr[0]);
                result[result.size()-1][1] = max(result[result.size()-1][1], curr[1]);
            }
            else {
                result.push_back(curr);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
int main() {
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    cout<<"\n";
    vector<vector<int>> res = s.merge(v);
    cout<<"[";
    for(int i = 0; i < res.size(); i++) {
        cout<<"["<<res[i][0]<<","<<res[i][1]<<"]";
    }
    cout<<"]";
}