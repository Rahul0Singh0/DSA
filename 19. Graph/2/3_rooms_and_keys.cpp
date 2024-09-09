// https://leetcode.com/problems/keys-and-rooms/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// bfs
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int neighbour : rooms[curr]) {
                if(visited.count(neighbour) == 0) {
                    // neighbour not yet visited
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        return visited.size() == rooms.size();
    }
    // also can use dfs
};

int main() {
    vector<vector<int>> rooms{{1},{2},{3},{}};
    Solution s;
    cout<<"\n"<<(bool)s.canVisitAllRooms(rooms);
}