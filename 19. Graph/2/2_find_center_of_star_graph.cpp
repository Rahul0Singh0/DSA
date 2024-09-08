// https://leetcode.com/problems/find-center-of-star-graph/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> v(n+2,0);
        for(auto e : edges) {
            int node1 = e[0];
            int node2 = e[1];
            v[node1]++;
            v[node2]++;
            if(v[node1]>1) return node1;
            else if(v[node2] >1) return node2;
        }
        return 0;
        /*int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];
        return (c == a or c == b) ? c : d; */
    }
};
int main() {
    vector<vector<int>> v{{1,2},{2,3},{4,2}};
    Solution s;
    cout<<"\n"<<s.findCenter(v);
}