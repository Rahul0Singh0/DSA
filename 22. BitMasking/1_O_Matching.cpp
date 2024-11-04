#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
int dp[22][1<<22];

// fast I/O template
void file_i_o() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int f(int i, int mask, int n, vector<vector<int>> &c) {
    if(i == n+1) {
        if(mask == 0) return 1;
        return 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int w = 1; w <= n; w++) {
        // bool available = ((1 << (w-1)) & mask == 0) ? 0 : 1; // parenthesis optimization must improve time
        bool available = (((1 << (w-1)) & mask) == 0) ? 0 : 1;
        if(available and c[i][w]) { // compatible
            ans = ((ans % mod) + (f(i+1, mask^(1<<(w-1)),n,c))%mod)%mod;
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    file_i_o();
    int n;
    cin>>n;
    vector<vector<int>> c(n+1, vector<int> (n+1)); // compatibility matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>c[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout<<f(1, (1<<n)-1, n, c);
    return 0;
}