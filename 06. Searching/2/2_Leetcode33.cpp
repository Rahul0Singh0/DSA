// Search in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, int t, int low, int high) {
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] == t) return mid;
            else if(nums[mid] > t) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
    int search1(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        int pivot = -1;
        // [3, 1], target = 1
        if(n == 2){
            if(nums[0] == target) return 0;
            else if(nums[1] == target) return 1;
            else return -1;
        }
        //finding pivot
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(mid == 0) low = mid+1;
            else if(mid == n-1) high = mid-1;
            else if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1]) {
                pivot = mid;
                break;
            } 
            else if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) {
                pivot = mid+1;
                break;
            } 
            else if(nums[mid] > nums[high]) low = mid+1;
            else high = mid-1;
        }
        if(pivot == -1) {// array is already sorted,no rotation
            low = 0; high = n-1;
            return binarySearch(nums, target, low, high);
        }
        //left binary search
        if(target >= nums[0] && target <= nums[pivot-1]) {
            low = 0;
            high = pivot-1;
            return binarySearch(nums, target, low, high);
        } else {
            low = pivot;
            high = n-1;
            return binarySearch(nums, target, low, high);
        }
        return -1;
    }
    int search2(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            const int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            if (nums[l] <= nums[m]) {  // nums[l..m] are sorted.
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else {  // nums[m..(n-1)] are sorted.
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};