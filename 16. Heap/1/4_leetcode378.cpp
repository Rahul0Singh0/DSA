//Kth smallest element in a sorted matrix 378
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
// Time : O(n*m + nm*log nm )
    // int kthSmallest(vector<vector<int>>& arr, int k) {
    //     vector<int> v;
    //     for(int i = 0; i < arr.size(); i++) {
    //         for(int j = 0; j < arr.size(); j++) {
    //             v.push_back(arr[i][j]);
    //         }
    //     }
    //     sort(v.begin(), v.end());
    //     return v[k-1];
    // }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }
        return pq.top();
    }
    // another method is binary search
};
int main() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++) {
        vector<int> t;
        for(int j =0; j < n; j++) {
            int e; cin>>e;
            t.push_back(e);
        }
        v.push_back(t);
        t.clear();
    }
    int k;
    cin>>k;
    Solution s;
    cout<<s.kthSmallest(v, k)<<endl;
} 