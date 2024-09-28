// Leetcode 542
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
// BFS
    vector<vector<int>> result;
    vector<vector<int>> zeroOneMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        result.empty();
        result.resize(n, vector<int>(m, 0));
        // vector<vector<int>> result(n, vector<int>(m, 0));
        // Store all sources
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    qu.push({i,j});
                }
            }
        }
        // we have added all the source
        qu.push({-1,-1});
        // vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up down left right
        while(not qu.empty()) {
            auto cell = qu.front();
            qu.pop();
            if(cell.first == -1 and cell.second == -1) break;
            else { // normal cell
                int i = cell.first;
                int j = cell.second;
                int k = i+1; // down
                while(k < n && grid[k][j]) {
                    int val = result[k-1][j] + grid[k][j];
                    if(result[k][j] != 0) {
                        result[k][j] = min(val, result[k][j]);
                    } else {
                        result[k][j] = val;
                    }
                    k++;
                }
                k = i-1; // up
                while(k >= 0 && grid[k][j]) {
                    int val = result[k+1][j] + grid[k][j];
                    if(result[k][j] != 0) {
                        result[k][j] = min(val, result[k][j]);
                    } else {
                        result[k][j] = val;
                    }
                    k--;
                } 
                k = j+1; // right
                while(j < m && grid[i][k]) {
                    int val = result[i][k-1] + grid[i][k];
                    if(result[i][k] != 0) {
                        result[i][k] = min(val, result[i][k]);
                    } else {
                        result[i][k] = val;
                    }
                    k++;
                }
                k = j-1; // left
                while(j >= 0 && grid[i][k]) {
                    int val = result[i][k+1] + grid[i][k];
                    if(result[i][k] != 0) {
                        result[i][k] = min(val, result[i][k]);
                    } else {
                        result[i][k] = val;
                    }
                    k--;
                }
            }
        }
        return result;
    }
    // Above solution Leetcode cannot accept due to background reason
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int n = mat.size();
        int m = mat[0].size();
        queue< pair<int, int> > qu;
        vector<vector<bool>> seen(n, vector<bool>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    seen[i][j] = true;
                    qu.emplace(i, j);
                    // qu.push({i, j}); // also can use
                }
            }
        } 

        while(not qu.empty()) {
            const auto [i, j] = qu.front();
            qu.pop();
            for(const auto& [di, dj] : dir) {
                const int nr = di + i;
                const int nc = dj + j;
                if(nr < 0 or nc < 0 or nr >= n or nc >= m) continue; // out of index
                if(seen[nr][nc]) continue; // already visit
                mat[nr][nc] = mat[i][j] + 1;
                qu.emplace(nr, nc);
                seen[nr][nc] = true;
            }
        }

        return mat;
    }
};
int main() {
    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    Solution s;
    // result.empty();
    // result.resize(grid.size(), vector<int>(grid[0].size(), 0));
    vector<vector<int>> result = s.zeroOneMatrix(grid);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}