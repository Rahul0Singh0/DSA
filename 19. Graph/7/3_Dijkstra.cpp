// https://www.hackerrank.com/challenges/primsmstsub/problem
#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp>> gr;
void add_edge(int u, int v, int w, int bidir=true) {
    gr[u].push_back({v,w});
    if(bidir) {
        gr[v].push_back({u,w});
    }
}

unordered_map<int,int> dijkstra(int src, int n) { // O(VlogV + ElogV)
    // min heap
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> via(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[i] = INT_MAX; // O(V)
    pq.push({0, src});
    mp[src] = 0;
    while(not pq.empty()) { // BFS loop = O(V+E) => Total = O((V+E)logV)
        // cout<<total_count<<"\n";
        pp curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert({curr.second});
        pq.pop();
        for(auto neighbour : gr[curr.second]) { 
            if(not vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second + mp[curr.second]) {
                pq.push({neighbour.second + mp[curr.second], neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second + mp[curr.second];
            }
        }
    } 
    return mp;
}

int main() {
    int n, m;
    cin>>n>>m;
    gr.resize(n, list<pp>()); // 0 based indexing
    while(m--) {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    int src;
    cin>>src;
    unordered_map<int,int> res = dijkstra(src, n);
    int dest;
    cin>>dest;
    cout<<res[dest]<<"\n";\
    // you can trace path using via list
    return 0;
}