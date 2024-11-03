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
            f(cand, t-cand[i], i+1, subset); // picked
            subset.pop_back(); // revert
        }
        // solution of repitition problem
        int j = i+1;
        while(cand[j] == cand[j-1]) j++;
        // avoid
        f(cand, t, j, subset); // not picked
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        f(candidates, target, 0, subset);
        return result;
    }
};