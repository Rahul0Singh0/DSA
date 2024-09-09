#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
using namespace std;
int v;// no of vertices
vector<list<int>> graph;
void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);
    if(bi_dir) {
        graph[dest].push_back(dest);
    }
}
void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto ele: graph[i]) {
            cout<<ele<<", ";
        }
        cout<<"\n";
    }
}
void dfs(int node, unordered_set<int> &visited) {
    visited.insert(node);
    for(auto neighbor : graph[node]) {
        if(not visited.count(neighbor)) {
            dfs(neighbor, visited);
        }
    }
}
int connected_components() {
    int result = 0;
    unordered_set<int> visited;
    for(int i = 0; i < v; i++) {
        // go to every vertex
        // if from a vertex we can initialise a dfs, we got one more cc
        if(visited.count(i) == 0) {
            result++;
            dfs(i, visited);
        }
    }
    return result;
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
    cout<<"\n No. of connected components: "<<connected_components()<<endl;
    return 0;
}