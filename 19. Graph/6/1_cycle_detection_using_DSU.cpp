// In Undirected Graph, detect a cycle
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}
// Time: E x log*(v) => log*(v) = constant
// Time: O(E)
bool Union(vector<int> &parent, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return true; // parent same of a and b
    if(rank[a] >= rank[b]) {
        rank[a]++;
        parent[b] = a;
    } else {
        rank[b]++;
        parent[a] = b;
    }
    return false;
}

int main() {
    int n, m;
    cin>>n>>m;
    // n is no. of elements, and m is no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    // initially each and every element has parent itself
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    while(m--) {
        int x, y;
        cin>>x>>y;
        bool b = Union(parent, rank, x, y);
        if(b == true) cout<<"Cycle detected\n";
    }
    cout<<"Cycle not detected\n";
    return 0;
}