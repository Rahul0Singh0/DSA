#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        int fo = 0; // fresh orange
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) fo++;
                else if(grid[i][j] == 2) qu.push({i, j}); // multisource bfs step
            }
        }
        // we have added all the source
        qu.push({-1,-1});
        int mins = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up down left right
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            if(cell.first == -1 and cell.second == -1) { // minute finish
                mins++;
                if(not qu.empty()) { // if queue is not empty
                    // then another minute start
                    qu.push({-1, -1});
                }
                else {
                    break;
                }
            }
            else { // normal cell
                int i = cell.first;
                int j = cell.second;
                for(int d = 0; d < 4; d++) {
                    int nr = i + dir[d][0]; // neighbouring row
                    int nc = j + dir[d][1]; // neighbouring col
                    if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue; // exit if out of grid
                    if(grid[nr][nc] == 2 or grid[nr][nc] == 0) continue; // if orange is rotten or empty
                    fo--; // if fresh orange
                    grid[nr][nc] = 2;
                    qu.push({nr, nc});
                }
            }
        }
        return (fo == 0) ? mins-1 : -1;
    }
};
int main() {
    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    Solution s;
    cout<<"\n"<<s.orangesRotting(grid)<<endl;
    return 0;
}