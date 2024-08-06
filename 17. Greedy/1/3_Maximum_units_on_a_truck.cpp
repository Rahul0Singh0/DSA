// https://leetcode.com/problems/maximum-units-on-a-truck/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }
    // Time : O(N*logN), Space : O(1)
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(), boxTypes.end(), cmp); 
       int profit = 0;
       for(int i = 0; i < boxTypes.size(); i++) {
          if(boxTypes[i][0] <= truckSize) {
            profit += boxTypes[i][0] * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
          }
          else {
            profit += truckSize*boxTypes[i][1];
            truckSize = 0;
          }
          if(truckSize == 0) break;
       }
       return profit;
    }
};
int main() {
    vector<vector<int>> v{{1,3},{2,2},{3,1}};
    int trucksize = 4+
    Solution S;
    int res = S.maximumUnits(v, trucksize);
    cout<<res;
    return 0;
}