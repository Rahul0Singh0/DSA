#include <iostream>
#include <vector>
using namespace std;

// T.C:  O(log*n)
int find(vector<int> &parent, int x) {
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

// T.C:  O(log*n)
void Union(vector<int> &parent, vector<int> &sz, vector<int> &minimal, vector<int> &maximal, vector<int> &rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);

    if(a == b) return; // both a and b are same set

    if(rank[a] > rank[b]) {
        rank[a]++;
        parent[b] = a;
        sz[a] += sz[b];
        maximal[a] = max(maximal[a], maximal[b]);
        minimal[a] = min(minimal[a], minimal[b]);
    } else {
        rank[b]++;
        parent[a] = b;
        sz[b] += sz[a];
        maximal[b] = max(maximal[a], maximal[b]);
        minimal[b] = min(minimal[a], minimal[b]);
    }
}

void file_i_o() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main() {

    // Fast I/O
    file_i_o();

    int n, m;
    cin>>n>>m;
    // n is no. of elements, and m is no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    vector<int> sz(n+1, 1);
    vector<int> minimal(n+1);
    vector<int> maximal(n+1);
    for(int i = 0; i <= n; i++) {
        parent[i] = minimal[i] = maximal[i] = i;
    }

    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            Union(parent, sz, minimal, maximal, rank, x, y);
        } else {
            int x;
            cin>>x;
            x = find(parent, x);
            // cout<<x<<"\n";
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<"\n";
        }
    }

    return 0;
}


/**
 * Input: 
 * 5 11
 * union 1 2
 * get 3
 * get 2
 * union 2 3
 * get 2
 * union 1 3
 * get 5
 * union 4 5
 * get 5
 * union 4 1
 * get 5
 * 
 * 
 * Output:
 * 3 3 1
 * 1 2 2
 * 1 3 3
 * 5 5 1
 * 4 5 2
 * 1 5 5
 * 
 * 
 */