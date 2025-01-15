// leetcode 40 backtracking problem
#include <bits/stdc++.h>
using namespace std;
void combination(vector<int>& arr, int t) {
    sort(arr.begin(), arr.end());
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
            if(i > idx && arr[i] == arr[i-1]) continue;
            combination.push_back(arr[i]);
            f(combination, rem-arr[i], i+1);
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
            dfs(comb, rem-arr[i], i+1); // take
            comb.pop_back();
        }
        // solution of repitition
        int j = i+1;
        while(j < arr.size() && arr[j] == arr[j-1]) j++;
        dfs(comb, rem, j); // avoid
    };
    dfs({}, t, 0);
}
int main() {
    vector<int> v{10,1,2,7,6,1,5};
    int target = 8;
    combination(v, target);
    return 0;
}