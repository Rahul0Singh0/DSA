// Leetcode 2080
#include <bits/stdc++.h>
using namespace std;
typedef unordered_map<int,int> umap;
class RangeFreqQuery {
public:
    vector<umap> st;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st.resize(4*n);
        buildTree(arr, 0, 0, n-1);
    }
    umap addMaps(umap &mp1, umap &mp2) {
        umap mp;
        for(auto p : mp1) {
            mp.insert(p);
        }
        for(auto p : mp2) {
            int key = p.first, freq = p.second;
            if(mp.find(key) == mp.end()) { // not found
                mp.insert(p);
            } else {
                mp[key] += freq;
            }
        }
        return mp;
    }
    void buildTree(vector<int> &arr, int i, int lo, int hi) {
        if(lo == hi) {
            int key = arr[lo], freq = 1;
            // st[i].insert({key, freq});
            (st[i])[key] = freq;
            return;
        }
        int mid = lo + (hi - lo)/2;
        buildTree(arr, 2*i+1, lo, mid);
        buildTree(arr, 2*i+2, mid+1, hi);
        st[i] = addMaps(st[2*i+1], st[2*i+2]);
    }
    int getFreq(int i, int lo, int hi, int &l, int &r, int &key) {
        if(l > hi or r < lo) return 0;
        if(lo >= l && hi <= r) {
            if(st[i].find(key) == st[i].end()) return 0;
            else return st[i][key];   
        }
        int mid = lo + (hi-lo)/2;
        int leftFreq = getFreq(2*i+1, lo, mid, l, r, key);
        int rightFreq = getFreq(2*i+2, mid+1, hi, l, r, key);
        return leftFreq + rightFreq;

    }
    int query(int left, int right, int value) {
        return getFreq(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */