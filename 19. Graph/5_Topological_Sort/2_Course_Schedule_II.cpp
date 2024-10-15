#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(auto neighbour: prerequisites[i]) {
                // i ----> neighbour
                indegree[neighbour]++;
            }
        }
        for(int i = 0; i < numCourses; i++) {
            cout<<indegree[i]<<" ";
        }
    }
};
int main() {
    Solution s;
    int n = 4;
    vector<vector<int>> graph{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    s.findOrder(n, graph);
    return 0;
}