#include <bits/stdc++.h>
using namespace std;
class DSU {
private:
    vector<int> parent;
    vector<int> Size;
public:
    DSU(int n) {
        parent.resize(n+1);
        Size.resize(n+1, 0);
        // initially each and every element has parent itself
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            Size[i] = i;
        }
    }
    
    int find1(int x) { 
        return parent[x] = (parent[x] == x) ? x : find1(parent[x]);
    }

    void Union(int a, int b) {
        a = find1(a);
        b = find1(b);
        if(a == b) return; // parent same of a and b
        if(Size[a] >= Size[b]) {
            Size[a] += Size[b];
            parent[b] = a;
        } else {
            Size[b] += Size[a];
            parent[a] = b;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mxRow = 0;
        int mxCol = 0;
        for(auto s : stones) {
            mxRow = max(mxRow, s[0]);
            mxCol = max(mxCol, s[1]);
        }
        int n = stones.size(); // no. of nodes
        DSU d(mxRow + mxCol + 1);
        unordered_map<int, int> stoneNode;
        for(auto s : stones) {
            int x = s[0];
            int y = s[1] + mxRow + 1;
            d.Union(x, y);
            stoneNode[x] = 1;
            stoneNode[y] = 1;
        }
        int cc = 0;
        for(auto s : stoneNode) {
            if(d.find1(s.first) == s.first) {
                cc++;
            }
        }
        return n - cc;
    }
};