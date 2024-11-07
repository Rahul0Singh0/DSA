#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int grid[4][4] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
int dp[10][1<<10];
// dfs
// Total Subproblems = n*(2^n)
int tsp(int curr, int mask, int n) {  // O((n^2) * (2^n))
    if(mask == (1<<n)-1) return grid[curr][0]; // at leaf, then connect(sum) that leaf to first node
    if(dp[curr][mask] != -1) {
        return dp[curr][mask];
    }
    int ans = INT_MAX;
    // all neighbour
    for(int ne = 0; ne < n; ne++) {
        if((mask & (1<<ne)) == 0) { // not visited
            ans = min(ans, grid[curr][ne] + tsp(ne, (mask|(1<<ne)), n));
        }
    }
    return dp[curr][mask] = ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cout<<tsp(0,1,4);
    return 0;
}