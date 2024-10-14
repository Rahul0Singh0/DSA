#include<bits/stdc++.h>
using namespace std;

int v;// no of vertices
vector<list<int>> graph;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(src);
    }
}

void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto ele: graph[i]) {
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

bool bfs(int src) {
    unordered_set<int> vis;
    queue<int> qu;
    vector<int> par(v, -1);
    qu.push(src);
    vis.insert(src);
    while(not qu.empty()) {
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[curr]) {
            if(vis.count(neighbour) and par[curr] != neighbour) return true;
            if(not vis.count(neighbour)) {
                vis.insert(neighbour);
                par[neighbour] = curr;
                qu.push(neighbour);
            }
        }
    }
    return false;
}

bool hasCycle() {
    unordered_set<int> vis;
    bool result = false;
    for(int i = 0; i < v; i++) { // it works for multiple components cause of we apply dfs for every node
        if(not vis.count(i)) {
            result = bfs(i);
            if(result == true) return true;
        }
    }
    return false;
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
    display();

    bool b = hasCycle();
    cout<<b<<" \n";

    return 0;
}