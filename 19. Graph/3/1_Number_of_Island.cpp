#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Solution {
public:
// BFS
// if any changes on grid except 0 and 1, leetcode will not allow 
// So, I am using 0 for visited land rather than -1
// Or anthor way, you can use another vector to mark visited
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int cc = 0; // stores the no. of connected components
        // try to initiate bfs on each and every cell
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '0') {
                    // it is a water body
                    continue;
                }
                // if(grid[r][c] == '-1') {
                //     // it is visited land
                //     continue;
                // }
                // new unvisited land piece found, i.e. new connected component
                cc++;
                grid[r][c]='0';//mark visited
                queue<pair<int,int>> qu;
                qu.push({r,c}); // store the src node
                while(not qu.empty()) {
                    auto curr = qu.front();
                    qu.pop();
                    // go to unvisited neighbors of the curr node
                    int currRow = curr.first;
                    int currCol = curr.second;
                    // top neighbor 
                    if(currRow-1 >= 0 && grid[currRow-1][currCol] == '1') {
                        // unvisited land piece
                        qu.push({currRow-1, currCol});
                        grid[currRow-1][currCol] = '0';
                    }
                    // down neighbor
                    if(currRow+1 < rows && grid[currRow+1][currCol] == '1') {
                        // unvisited land piece
                        qu.push({currRow+1, currCol});
                        grid[currRow+1][currCol] = '0';
                    }
                    // left neighbour
                    if(currCol-1 >= 0 && grid[currRow][currCol-1] == '1') {
                        // unvisited land piece
                        qu.push({currRow, currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    // right neighbour
                    if(currCol+1 < cols && grid[currRow][currCol+1] == '1') {
                        // unvisited land piece
                        qu.push({currRow, currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }
                } 
            }
        }
        return cc;
    }
    // DFS
     int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i == grid.size() || j < 0 || j == grid[0].size()) return;
        if(grid[i][j] != '1') return;
        grid[i][j] = '2'; // mark 2 as visited
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
};
