#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
// TLE, Time complexity: O(n^2), Space complexity: O(1)
// The brute force solution is to iterate through all the subarrays and count the number of maximum elements in each subarray.
    long long countSubarrays (vector<int> &nums, int k) {
        const int mx_ele = ranges::max(nums);
        long long int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = i; j < nums.size(); j++) {
                if (mx_ele == nums[j]) {
                    cnt++;
                }

                if (cnt >= k) {
                    res++;
                }
            }
        }
        return res;
    }
    // Sliding Window O(N)
    long long fun(vector<int> &nums, int k) {
        const int mx_ele = ranges::max(nums);
        long long int res = 0;
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == mx_ele) cnt++;

            while (cnt == k) {
                if (nums[j] == mx_ele) cnt--;
                j++; // count number of subarrays with atleast k elements
            }

            res += j;
        }
        return res;
    }
};