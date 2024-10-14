#include <iostream>
#include <vector>
using namespace std;

// T.C:  O(log*n)
int find(vector<int> &parent, int x) {
    // This method returns which group/cluster x belongs to
    // using path compression step means final ans store 
    return parent[x] = (parent[x] == x) ? x : find(parent, parent[x]);
}

// T.C:  O(log*n)
// Union by Rank(Improved version)
// void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
//     a = find(parent, a);
//     b = find(parent, b);
//     if(a == b) return; // both a and b are same set
//     // Union by rank
//     if(rank[a] >= rank[b]) {
//         rank[a]++;
//         parent[b] = a;
//     } else {
//         rank[b]++;
//         parent[a] = b;
//     }
// }

// Union by size
void Union(vector<int> &parent, vector<int> &Size, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if(a == b) return; // parent same of a and b
    if(Size[a] >= Size[b]) {
        Size[a] += Size[b];
        parent[b] = a;
    } else {
        Size[b] += Size[a];
        parent[a] = b;
    }
}


int main() {
    int n, m;
    cin>>n>>m;
    // n is no. of elements, and m is no. of queries
    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);
    vector<int> Size(n+1);

    // initially each and every element has parent itself
    for(int i = 0; i <= n; i++) {
        parent[i] = i;
        Size[i] = i;
    }
    while(m--) {
        string str;
        cin>>str;
        if(str == "union") {
            int x, y;
            cin>>x>>y;
            // Union(parent, rank, x, y);
            Union(parent, Size, x, y);
        } else {
            int x;
            cin>>x;
            cout<<find(parent, x)<<"\n";
        }
    }
    return 0;
}