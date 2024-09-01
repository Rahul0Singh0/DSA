#include<bits/stdc++.h>
using namespace std;
int v;// no of vertices
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> paths;
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}
void dfs(int curr, int end, vector<int> &path) {
    if(curr == end) {
        path.push_back(curr);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);//visited mark
    path.push_back(curr);
    for(auto neighbour : graph[curr]) {
        if(not visited.count(neighbour)) { // if count is zero then not visited neighbour
            dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}
// bool dfs(int curr, int end) {
//     if(curr == end) return true;
//     visited.insert(curr);//visited mark
//     for(auto neighbour : graph[curr]) {
//         if(not visited.count(neighbour)) { // if count is zero then not visited neighbour
//             bool result = dfs(neighbour, end);
//             if(result) return true;
//         }
//     }
//     return false; // if any path is not found
// }
void allPath(int src, int dest) {
    vector<int> v;
    dfs(src,dest,v);
}
int main() {
    cout<<"Enter no of vertices: ";
    cin>>v;
    graph.resize(v, list<int>());
    int e;//no of edges
    cout<<"Enter no of edges: ";
    cin>>e;
    while(e--) {
        int s,d;
        cout<<"src to dest: ";
        cin>>s>>d;
        add_edge(s,d);
    }
    int x,y;
    cout<<"src and dest node to find any path: ";
    cin>>x>>y;
    allPath(x,y);
    for(auto path : paths) {
        for(auto p : path) {
            cout<<p<<" ";
        }
        cout<<"\n";
    }
    return 0;
}