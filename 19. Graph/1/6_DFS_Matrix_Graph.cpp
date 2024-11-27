#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;
int v = 7;
const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> vis(v, vector<bool> (v, false));

bool isSafe(vector<vector<int>>& graph, int i, int j) {
    return i >= 0 && j >= 0 && i < v && j < v && !vis[i][j];
}

void dfs(vector<vector<int>>& graph, int i, int j) {
    if(i >= v || j >= v) return;
    vis[i][j] = true;
    if(graph[i][j] == 1) {
        cout<<i<<" ----> "<<j<<endl;
    }
    // cout<<graph[i][j]<<" ";
    for(int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if(isSafe(graph, x, y)) {
            dfs(graph, x, y);
        }
    }
}

int main() {
    // v = 7;
    vector<vector<int>> graph {
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0}
    };
    // cout<<"Enter no.of vertices and edges";
    // cin>>v>>e;
    // vector<vector<int>> graph(v, vector<int>(v, 0));
    // int dir = 1; // by default directed
    // cout<<"Directed(1) or Undirect(0)";
    // cin>>dir;
    // if(dir == 0) cout<<"Enter only one way src to des in undirected graph"<<endl;
    // int weighted = 1;
    // cout<<"Weighted(1) or unweighted(0)";
    // cin>>weighted;
    // int i,j;
    // for(int k = 1; k <= e; k++) {
    //     cout<<"Enter src -> dest : ";
    //     cin>>i>>j;
    //     if(i < v && j < v) {
    //         int w = 1;
    //         if(weighted == 1) {
    //             cout<<"Enter weight of this edge: ";
    //             cin>>w;
    //         }
    //         graph[i][j] = w;
    //         if(dir != 1) graph[j][i] = w;
    //     }
    //     else cout<<"Invalid Edge!";
    // }
    dfs(graph, 0, 0);

    // for(int i = 0; i < v; i++) {
    //     for(int j = 0; j < v; j++) {
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}