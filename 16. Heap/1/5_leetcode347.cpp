// Top k frequent Elements (347)
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    typedef pair<int,int> p; // <freq, ele>
    vector<int> kFrequentElements(vector<int>& arr, int k) {
        unordered_map<int, int> freq;// <ele, freq>
        for(int i: arr) freq[i]++;
        priority_queue<p, vector<p>, greater<p>> pq; // min heap
        for(p pr : freq) {
            pq.push({pr.second, pr.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second); // element assign
            pq.pop();
        }
        return ans; // result will be any order does not matter
    }

    // Using custom comparitor
    bool comp(p& a, p& b) {
        return a.second < b.second;
    }
    vector<int> kFrequentElements1(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i : arr) mp[i]++;
        vector<p> v;
        for(p pr : mp) {
            v.push_back(pr);
        }
        sort(v.begin(), v.end(), comp);
        return {v[v.size()-1].second, v[v.size()-2].second};
    }
};
int main() {
    vector<int> v;
    int n;
    std::cin>>n;
    for(int i = 0; i < n; i++) {
        int e;
        std::cin>>e;
        v.push_back(e);
    }
    int k;
    std::cin>>k;
    Solution s;
    vector<int> ans = s.kFrequentElements(v,k);
    for(int i = 0; i < ans.size(); i++)
        std::cout<<ans[i]<<" ";
    vector<int> ans1 = s.kFrequentElements1(v, k);
    for(int i = 0; i < ans1.size(); i++)
        std::cout<<ans1[i]<<" ";
    return 0;
}