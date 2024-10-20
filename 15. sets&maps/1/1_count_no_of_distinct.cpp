// leetcode 2442
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int rev(int n) {
        int r = 0;
        while(n) {
            r = r*10+(n%10);
            n /= 10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set<int> cnt;
        for(auto i : nums) {
            cnt.insert(i);
            int r = rev(i);
            cnt.insert(r);
        }
        return cnt.size();
    }
};