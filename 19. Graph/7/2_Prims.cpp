// https://www.hackerrank.com/challenges/primsmstsub/problem
#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
// - DS - visited set, priority_queue<pair>, unordered_map
// - insert the pair of <- 1, src> in the pq.
// - one by one remove the root element of the pq
// - if the root element is already visited, we will just continue.
// - we mark the root visited
// - we store the wt of the pair in the ans
// - update the mapping
// - go to every neighbour of the curr node, and only add those which are non visited and have better wt. proposition.

vector<list<pp>> gr;
void add_edge(int u, int v, int w, int bidir=true) {
    gr[u].push_back({v,w});
    if(bidir) {
        gr[v].push_back({u,w});
    }
}

ll prims(int src, int n) {
    // min heap
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int, int> mp;
    for(int i = 0; i <= n; i++) mp[i] = INT_MAX;
    pq.push({0, src});
    mp[src] = 0;
    int total_count = 0; // 0 -> n-1 edges
    int result = 0; // sum of weights
    while(total_count < n and !pq.empty()) {
        // cout<<total_count<<"\n";
        pp curr = pq.top();
        if(vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert({curr.second});
        total_count++;
        result += curr.first;
        pq.pop();
        for(auto neighbour : gr[curr.second]) {
            if(not vis.count(neighbour.first) and mp[neighbour.first] > neighbour.second) {
                pq.push({neighbour.second, neighbour.first});
                par[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
            }
        }
    } 
    return result;
}

int main() {
    int n, m;
    cin>>n>>m;
    gr.resize(n+1, list<pp>());
    while(m--) {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    int src;
    cin>>src;
    cout<<prims(src, n);
    return 0;
}