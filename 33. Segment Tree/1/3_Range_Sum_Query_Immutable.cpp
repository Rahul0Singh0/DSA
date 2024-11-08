// Leetcode 303
#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> arr; // prefix array
    // Time: O(N) one time for a array
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i-1];
        }
    }
    // Time: O(1)
    int sumRange(int left, int right) {
        if(left == 0) return arr[right];
        return arr[right] - arr[left-1];
    }
};

class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
    }
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++) {
            sum += arr[i];
        }   
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */