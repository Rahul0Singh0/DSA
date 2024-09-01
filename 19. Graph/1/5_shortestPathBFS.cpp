#include<bits/stdc++.h>
using namespace std;
int v;// no of vertices
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> paths;
void add_edge(int src, int dist, bool bi_dir = true) {
    graph[src].push_back(dist);
    if(bi_dir) {
        graph[dist].push_back(src);
    }
}
// dist vector store shortest path distance between src to all node
void bfs(int src, vector<int>& dist) {
    queue<int> q;
    visited.clear();
    dist.resize(v, INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    q.push(src);
    while(not q.empty()) {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();
        for(auto neighbour : graph[curr]) {
            if(not visited.count(neighbour)) {
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour] = dist[curr] + 1; // distance calculate and store
            }
        }
    }
    cout<<endl;
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
        cout<<"src to dist: ";
        cin>>s>>d;
        add_edge(s,d);
    }
    int x;
    cout<<"Enter source node: ";
    cin>>x;
    vector<int> dist;
    bfs(x,dist);
    for(auto i : dist) {
        cout<<i<<" ";
    }
    return 0;
}