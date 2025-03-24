/**
 * Leetcode 1
 * Find the doublet in the array whose sum is equal to the given value x.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// In Leetcode 1, find out only one possible solution
// This two pointer method is not working for every cases 
void twoPointer(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size()-1;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == target) {
            cout<<"<"<<l<<","<<r<<">"<<endl;
            l++, r++;
        } else if(sum < target) {
            l++;
        } else {
            r--;
        }
    }
}

void twoSum(vector<int>& arr, int target) {
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < arr.size(); i++) {
        int rem = target - arr[i];
        if(mp.find(rem) != mp.end()) {
            for(int j : mp[rem]) {
                cout<<"<"<<j<<","<<i<<">"<<endl;
            }
        }
        mp[arr[i]].push_back(i);
    }
}

int main() {
    vector<int> arr{1, 3, 2, 4, 3, 4, 1, 6};
    int target = 7;
    int n = 8;
    // Bruteforce: O(N^2)
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(target == arr[i] + arr[j]) cout<<"<"<<i<<","<<j<<">"<<endl;
        }
    }
    cout<<endl;
    twoPointer(arr, target);
    return 0;
}