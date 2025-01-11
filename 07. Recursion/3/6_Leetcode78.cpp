#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> result;
void f(vector<int>& nums, vector<int> subset, bool flag, int i) {
    if(i == nums.size()) {
        result.push_back(subset);
        return;
    }
    f(nums, subset, true, i+1);
    subset.push_back(nums[i]);
    f(nums, subset, true, i+1);
    subset.pop_back();
}

// void f(vector<int>& nums, vector<int> subset, bool flag, int i) {
//     if(i == nums.size()) {
//         result.push_back(subset);
//         subset.clear();
//         return;
//     }
//     int a = nums[i], b = nums[i+1]; // out of bound
//     if(a == b) {
//         f(nums, subset, false, i+1);
//     } else {
//         f(nums, subset, true, i+1);
//     }
//     if(flag) subset.push_back(a), f(nums, subset, true, i+1);
// }

// backtracking solution available in backtracking topics

int main() {
    vector<int> v{1, 3, 2};
    result.clear();
    vector<int> subset;
    f(v, subset, true, 0);
    for(auto subset : result) {
        for(auto s : subset) {
            cout<<s;
        }
        cout<<endl;
    }
    return 0;
}