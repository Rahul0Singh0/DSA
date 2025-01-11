#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
void f(vector<int>& nums, vector<int> subset, int i, int k) {
    if(i == nums.size()) {
        if(subset.size() == k) 
            result.push_back(subset);
        return;
    }
    if(subset.size() + (nums.size()-i) < k) {return;}
    f(nums, subset, i+1, k);
    subset.push_back(nums[i]);
    f(nums, subset, i+1, k);
    // while backtracking
    subset.pop_back();
}

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    result.clear();
    vector<int> subset;
    f(v, subset, 0, 3);

    for(auto subset : result) {
        for(auto s : subset) {
            cout<<s;
        }
        cout<<endl;
    }
    return 0;
}