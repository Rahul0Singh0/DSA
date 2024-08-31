#include<iostream>
#include<vector>
using namespace std;
int main() {
    // vector<vector<int>> g;
    int v,e;
    cout<<"Enter no.of vertices and edges";
    cin>>v>>e;
    // g.clear();
    // g.resize(v,vector<int>(v,0));
    int g[v+1][v+1] = {0};
    int dir = 1; // by default directed
    cout<<"Directed(1) or Undirect(0)";
    cin>>dir;
    if(dir == 0) cout<<"Enter only one way src to des in undirected graph"<<endl;
    int weighted = 1;
    cout<<"Weighted(1) or unweighted(0)";
    cin>>weighted;
    int i,j;
    for(int k = 1; k <= e; k++) {
        cout<<"Enter src -> dest : ";
        cin>>i>>j;
        if(i <= v && j <= v) {
            int w = 1;
            if(weighted == 1) {
                cout<<"Enter weight of this edge: ";
                cin>>w;
            }
            g[i][j] = w;
            if(dir != 1) g[j][i] = w;
        }
        else cout<<"Invalid Edge!";
    }
    for(int i = 1; i <= v; i++) {
        for(int j = 1; j <= v; j++) {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}