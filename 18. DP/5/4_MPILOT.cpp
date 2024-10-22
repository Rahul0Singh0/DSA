// https://www.spoj.com/problems/MPILOT/
#include <iostream>
#include <vector>
#include <cstring>
#define ll long long int
using namespace std;
int n;
vector<int> cap(10005, 0); // salary as captain
vector<int> as(10005, 0); // salary as assistant
int dp[10005][10005];
// x => sal(Ass) - sal(captain)
ll f(int i, int x) {
    if(dp[i][x] != -1) return dp[i][x];
    if(i == n) return 0; // all members are tested
    if(x == 0) return dp[i][x] = f(i+1, x+1) + as[i];
    else if(x == n-i) return dp[i][x] = f(i+1, x-1) + cap[i];
    else return dp[i][x] = min(f(i+1,x+1)+as[i], f(i+1,x-1)+cap[i]);
}
int main() {
    cin>>n;
    for(int i =0; i < n; i++) {
        cin>>cap[i]>>as[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = as[0] + f(1, 1);
    cout<<dp[0][0];
    return 0;
}