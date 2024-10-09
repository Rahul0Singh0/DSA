// Leetcode 286 primium problem similar to 0 1 matrix (542)
#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;
class Solution {
public:
    vector<vector <int>> fun(vector<vector <int>>& v) {
        vector<vector <bool>> vis(v.size(), vector<bool>(v[0].size()));
        queue<pair<int, int>> q; 
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                if(v[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
                if(v[i][j] == -1) vis[i][j] = true;
            }
        }
        vector<vector <int>> dir {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(not q.empty()) {
            auto [i, j] = q.front(); // structured bindings
            q.pop();
            for(auto d : dir) {
                int ni = d[0] + i;
                int nj = d[1] + j;
                if(ni < 0 or ni >= v.size() or nj < 0 or nj >= v[0].size()) continue;
                if(vis[ni][nj]) continue; // skip wall and gate
                if(v[ni][nj] == inf) {
                    v[ni][nj] = 0;
                }
                v[ni][nj] = v[i][j] + 1;
                q.push({ni, nj});
                vis[ni][nj] = true;
            }
        }
        return v;
    } 
};
int main() {
    Solution s;
    vector<vector <int>>v{{inf, -1, 0, inf}, {inf, inf, inf, -1}, {inf, -1, inf, -1}, {0, -1, inf, inf}};
    vector<vector <int>> res = s.fun(v);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}