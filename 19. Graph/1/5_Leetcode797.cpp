// All Paths from source to target
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<int> vis;
    vector<vector<int>> paths;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int src, int dest) {
        if(src == dest) {
            path.push_back(src);
            paths.push_back(path);
            path.pop_back();
        }
        vis.insert(src);
        path.push_back(src);
        for(auto neighbour : graph[src]) {
            if(not vis.count(neighbour)) {
                dfs(graph, neighbour, dest);
            }
        }
        path.pop_back();
        vis.erase(src);
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size()-1);
        return paths;
    }
};