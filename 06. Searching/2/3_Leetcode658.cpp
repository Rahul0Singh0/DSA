#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;
        while(l < r) {
            const int m = l + (r - l) / 2;
            if(x - arr[m] <= arr[m + k] - x) r = m;
            else l = m + 1;
        }
        return {arr.begin() + l, arr.begin() + l + k};
    }
};

class Algo {
public:
    void display(vector<int>& arr) {
        for(auto e: arr) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
};

int main() {
    vector<int> arr{1,1,2,3,4,5};
    int k = 4;
    int x = -1;
    Solution s;
    vector<int> ans = s.findClosestElements(arr, k, x);
    Algo a;
    a.display(ans);
}