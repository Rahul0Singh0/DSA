#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

vector<vector <bool> > vis;

void bfs(vector<vector <char> >& v, pair<int, int> src) {
    queue <pair <int, int> > q;
    vector<vector <int> > dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // vis[src.first][src.second] = true;
    q.push({src.first, src.second});
    while(not q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if(v[x][y] == '-1') break;
        v[x][y] = '-1';
        for(auto d : dir) {
            int x1 = d[0] + x;
            int y1 = d[1] + y; 
            if(v[x1][y1] == '0') {
                // vis[x1][y1] = true;
                // v[x1][y1] = '-1';
                q.push({x1, y1});
            }
        }
    }
    return;
}

vector<vector <char> > fun(vector<vector <char> >& v) {
    // bfs apply on the border
    for(int i = 0; i < v.size(); i++) {
        if(v[i][0] == '0') bfs(v, {i, 0});
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i][v.size()-1] == '0') bfs(v, {i, v.size()-1});
    }
    for(int j = 0; j < v[0].size(); j++) {
        if(v[0][j] == '0') bfs(v, {0, j});
    }
    for(int j = 0; j < v[0].size(); j++) {
        if(v[v[0].size()-1][j] == '0') bfs(v, {v[0].size()-1, j});
    }
    // update
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == '0') v[i][j] = 'x';
        }
    }
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            // if(v[i][j] == '0') v[i][j] = 'x';
            if(v[i][j] == '1') v[i][j] = '0';
        }
    }
    return v;
}

int main() {
    vector<vector <char> > v = {
        {'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', '0', '0', 'x'},
        {'x', 'x', 'x', 'x', 'x'},
        {'x', 'x', '0', '0', '0'},
        {'x', 'x', '0', '0', 'x'},
        {'x', 'x', 'x', 'x', '0'}};
    vis.clear();
    vis.resize(v.size(), vector<bool> (v[0].size(), false));

    vector<vector <char> >res = fun(v);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}