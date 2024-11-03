#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result; 
    void f(vector<int> &cand, int t, int i, vector<int> &subset) {
        if(t == 0) {
            // we found a subset which sum to target
            result.push_back(subset);
            return;
        }
        if(i == cand.size()) return;
        if(cand[i] <= t) {
            subset.push_back(cand[i]);
            f(cand, t-cand[i], i, subset); // picked
            subset.pop_back(); // revert
        }
        // solution of repitition problem
        int j = i+1;
        // while(j < cand.size() and cand[j] == cand[j-1]) j++;
        f(cand, t, j, subset); // avoid case (not picked)
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        f(candidates, target, 0, subset);
        return result;
    }
};