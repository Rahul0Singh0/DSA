#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
void f(vector<int>& nums, vector<int> subset, int i) {
    if(i == nums.size()) {
        result.push_back(subset);
        return;
    }
    f(nums, subset, i+1);
    subset.push_back(nums[i]);
    f(nums, subset, i+1);
    subset.pop_back(); // reverting step of backtracking
}
void dfs(vector<int>& nums, vector<int> subset, int i) {
    result.push_back(subset);
    for(int k = i; k < nums.size(); k++) {
        subset.push_back(nums[k]);
        dfs(nums, subset, k+1);
        subset.pop_back(); 
    }
}
int main() {
    vector<int> v{1, 2, 3};
    result.clear();
    vector<int> subset;
    // f(v, subset, 0);
    dfs(v, subset, 0);
    for(auto subset : result) {
        for(auto s : subset) {
            cout<<s;
        }
        cout<<endl;
    }
    return 0;
}