#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    // using max heap
    int kthSmallest(vector<int>& nums, int k) {
         priority_queue<int> pq;
         for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
         }
         return pq.top();
    }
    int kthLargest(vector<int>& nums, int k) {
         priority_queue<int, vector<int>, greater<int>> pq;
         for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
         }
         return pq.top();
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
    cout<<s.kthSmallest(v, k)<<endl;
    cout<<s.kthLargest(v, k)<<endl;
} 