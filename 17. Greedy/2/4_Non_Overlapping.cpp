#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0;
        int lastEndTime = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < lastEndTime) {
                ans++;
            }
            else {
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    cout<<"\n"<<s.eraseOverlapIntervals(v);
    return 0;
}