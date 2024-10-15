// https://leetcode.com/problems/minimum-knight-moves/

#include<iostream>
#include<queue>
#include<vector>
#include<set>
using namespace std;

struct Solution {
    int minKnightMoves(int x, int y) {
        queue<pair<int, int>> qu;
        set<pair<int, int>> vis; // log(n)
        // vector<vector<bool>> vis(700, vector<bool> (700)); // constant time 
        vector<vector<int>> dir = {{-1, 2}, {-1, -2}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {2, -1}, {2, 1}};
        vis.insert({0, 0});
        qu.push({0, 0});
        int cnt = 0;
        while(not qu.empty()) {
            // Traverse nodes level by level.
            for(int k = qu.size(); k > 0; --k) {
                auto [i, j] = qu.front();
                qu.pop();
                // if reached the target cell
                if(i == x && j == y) return cnt;
                // visits all possible moves from current node
                for(auto d : dir) {
                    int ni = d[0] + i;
                    int nj = d[1] + j;
                    if(vis.find({ni, nj}) == vis.end()) {
                        vis.insert({ni, nj});
                        qu.push({ni, nj});
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

int main() {
    Solution s;
    int x, y;
    cin>>x>>y;
    cout<<s.minKnightMoves(x, y);
    return 0;
}