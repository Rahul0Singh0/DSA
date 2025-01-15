// leetcode 39
// Backtracking problem
#include <bits/stdc++.h>
using namespace std;
void combination(vector<int>& arr, int t) {
    // Method 1
    function<void(vector<int>,int,int)> f = [&](vector<int> combination, int rem, int idx) {
        if(rem == 0) {
            for(int c : combination) {
                cout<<c<<" ";
            }
            cout<<endl;
            return;
        }
        if(rem < 0) return;
        for(int i = idx; i < arr.size(); i++) {
            combination.push_back(arr[i]);
            f(combination, rem-arr[i], i);
            combination.pop_back();
        }
    };
    // f({}, t, 0);
    // Method 2
    function<void(vector<int>,int,int)> dfs = [&](vector<int> comb, int rem, int i) {
        if(rem == 0) {
            for(int c : comb) {
                cout<<c<<" ";
            }
            cout<<endl;
            return;
        }
        if(i == arr.size()) return;
        if(arr[i] <= rem) {
            comb.push_back(arr[i]);
            dfs(comb, rem-arr[i], i); // take
            comb.pop_back();
        }
        dfs(comb, rem, i+1); // avoid
    };
    dfs({}, t, 0);
}
int main() {
    vector<int> v{2,3,5};
    int target = 8;
    combination(v, target);
    return 0;
}