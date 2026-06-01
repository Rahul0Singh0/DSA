#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, vector<int> subset, int i) {
        result.push_back(subset);
        for(int k = i; k < nums.size(); k++) {
            if (k > i && nums[k] == nums[k - 1])
                continue;
            subset.push_back(nums[k]);
            dfs(nums, subset, k+1);
            subset.pop_back(); 
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, {}, 0);
        return result;
    }
};