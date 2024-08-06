// Given an array of N elements, 
// where each element is at most K away from its target position, 
// devise an algorithm that sorts in O(N log K) time.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
// using min heap
    vector<int> kSorted(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        // vector<int> ans;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++) {
           pq.push(nums[i]);
           if(pq.size() > k) {
            //   ans.push_back(pq.top());
              nums[idx++] = pq.top();
              pq.pop();
           }
        }
        while(!pq.empty()) {
            // ans.push_back(pq.top());
            nums[idx++] = pq.top();
            pq.pop();
        }
        // return ans;
        return nums;
    }
};
int main() {
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int e;
        cin>>e;
        v.push_back(e);
    }
    int k;
    cin>>k;
    Solution s;
    vector<int> ans(s.kSorted(v, k));
    for(int i = 0; i < ans.size(); i++) 
        cout<<ans[i]<<" ";
} 