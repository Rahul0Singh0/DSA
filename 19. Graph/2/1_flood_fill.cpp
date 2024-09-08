// https://leetcode.com/problems/flood-fill/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(color == image[sr][sc]) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    // the below function will do dfs from currRow, currCol, to it's neighbours containing initialColor
    void dfs(vector<vector<int>> &image, int currRow, int currCol, int initialColor, int newColor) {
        int n = image.size(); // total rows
        int m = image[0].size(); // total cols
        if(currRow < 0 or currCol < 0 or currRow >= n or currRow >= m) {
            return; // you are outside the grid
        }
        // if the cell you landed is not of initial color
        if(image[currRow][currCol] != initialColor) return;
        image[currRow][currCol] = newColor;
        dfs(image, currRow+1, currCol, initialColor, newColor); // down
        dfs(image, currRow, currCol-1, initialColor, newColor); // left
        dfs(image, currRow-1, currCol, initialColor, newColor); // up
        dfs(image, currRow, currCol+1, initialColor, newColor); // right
    }
};

int main() {
    vector<vector<int>> image{{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    Solution s;
    vector<vector<int>> newImage = s.floodFill(image,sr,sc,color);
    for(auto a : newImage) {
        for(auto i : a) {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}