// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/submissions/1341348861/
// 1005
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        // initialized using heapify taking O(N)
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i]; // O(N)
        while(k--) {
            int element = pq.top();
            if(element == 0) break;
            pq.pop(); // remove smallest value log2(N)
            sum -= element;
            pq.push(-1*element);
            sum += (-element);
        }
        return sum;
    // Time: O(K*N)
     int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        while(k--) {
            int min_ele = INT_MAX;
            int idx;
            for(int i = 0; i < n; i++) {
                if(min_ele > nums[i]) {
                    idx = i;
                    min_ele = nums[i];
                }
            }
            if(min_ele == 0) break;
            nums[idx] *= -1;
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return sum;
    }
};
