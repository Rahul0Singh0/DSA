#include<iostream>
#include<list>
#include<vector>
using namespace std;
int v;// no of vertices
// vector<list<int>> graph;
vector<list<pair<int,int>>> graph; // pair<destination, weight>
void add_edge(int src, int dest, int wt, bool bi_dir = true) {
    graph[src].push_back({dest,wt});
    if(bi_dir) {
        graph[dest].push_back({src,wt});
    }
}
void display() {
    for(int i = 0; i < graph.size(); i++) {
        cout<<i<<" -> ";
        for(auto ele: graph[i]) {
            cout<<"{"<<ele.first<<":"<<ele.second<<"},";
        }
        cout<<"\n";
    }
}
int main() {
    cout<<"Enter no of vertices: ";
    cin>>v;
    graph.resize(v, list<pair<int,int>>());
    int e;//no of edges
    cout<<"Enter no of edges: ";
    cin>>e;
    while(e--) {
        int s,d;
        cout<<"src to dest: ";
        cin>>s>>d;
        int w;
        cout<<"Enter weight of "<<s<<" to "<<d<<" : ";
        cin>>w;
        add_edge(s,d,w);
    }
    display();
    return 0;
}