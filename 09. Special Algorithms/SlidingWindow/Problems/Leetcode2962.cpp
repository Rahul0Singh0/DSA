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
};