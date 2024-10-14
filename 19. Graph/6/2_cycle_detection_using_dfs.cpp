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

bool dfs(int src, int parent, unordered_set<int> &vis) {
    vis.insert(src);
    for(auto neighbour: graph[src]) {
        if(vis.count(neighbour) and neighbour != parent) {
            // cycle detect
            return true;
        }
        if(not vis.count(neighbour)) {
            bool res = dfs(neighbour, src, vis);
            if(res == true) return true;
        }
    }
    return false;
}

bool hasCycle() {
    unordered_set<int> vis;
    bool result = false;
    for(int i = 0; i < v; i++) { // it works for multiple components cause of we apply dfs for every node
        if(not vis.count(i)) {
            result = dfs(i, -1, vis);
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