#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void BubbleSort(vector<int>& v) {
        int n = v.size();
        for(int i = 0; i < n-1; i++) {// n-1 passes
           for(int j = 0; j < n-1-i; j++) { // n-1-i camparisons
              if(v[j] > v[j+1]) swap(v[j], v[j+1]);
           }
        }
    }
    // Stablility maintain
    void BubbleSort1(vector<int>& v) {
        int n = v.size();
        int flag;
        for(int i = 0; i < n-1; i++) {// n-1 passes
        flag = 0;
           for(int j = 0; j < n-1-i; j++) { // n-1-i camparisons
              if(v[j] > v[j+1]) {
                flag = 1;
                swap(v[j], v[j+1]);
              }
           }
           if(flag == 0) return; // already sorted
        }
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
    Solution s;
    s.BubbleSort(v);
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
} 