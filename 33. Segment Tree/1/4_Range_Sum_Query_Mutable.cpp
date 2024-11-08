// Leetcode 307
#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n);
        buildTree(nums, 0, 0, n-1);
    }

    void buildTree(vector<int>& nums, int i, int lo, int hi) {
        if(lo == hi) {
            st[i] = nums[hi];
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(nums, 2*i+1, lo, mid); // left subtree
        buildTree(nums, 2*i+2, mid+1, hi); // right subtree
        st[i] = st[i*2+1] + st[2*i+2];
    }
    
    void updateVal(int i, int lo, int hi, int idx, int val) {
        if(lo == hi) {
            st[i] = val;
            return;
        }
        int mid = lo + (hi-lo)/2;
        if(idx <= mid) updateVal(2*i+1, lo, mid, idx, val);
        else updateVal(2*i+2, mid+1, hi, idx, val);
        st[i] = st[2*i+1] + st[2*i+2];
    }

    void update(int index, int val) {
        updateVal(0,0,n-1,index,val);
    }

    // get sum O(log(n))
    int getSum(int i, int lo, int hi, int &l, int &r) {
        if(l > hi or r < lo) return 0;
        if(lo >= l and hi <= r) return st[i];
        int mid = lo + (hi - lo) / 2;
        int leftSum = getSum(2*i+1, lo, mid, l, r);
        int rightSum = getSum(2*i+2, mid+1, hi, l, r);
        return leftSum + rightSum;
    }

    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */