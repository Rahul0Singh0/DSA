// D. Badluck Island Codeforces
// https://codeforces.com/problemset/problem/540/D
#include <iostream>
#include <cstring>
#include <iomanip>
#define ld long double
#define ll long long int
using namespace std;
ld dp[105][105][105];
// For Rock
ld fr(int r, int s, int p) {
    if(r == 0 or s == 0) return 0.0;
    if(p == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*s + s*p + p*r;
    ld ans = 0.0;
    ans += fr(r-1,s,p)*((r*p)/total);
    ans += fr(r,s-1,p)*((r*s)/total);
    ans += fr(r,s,p-1)*((p*s)/total);
    return dp[r][s][p] = ans;
}
// Scissor
ld fs(int r, int s, int p) {
    if(s == 0 or p == 0) return 0.0;
    if(r == 0) return 1.0;
    if(dp[r][s][p] > -0.9) return dp[r][s][p];
    ld total = r*s + s*p + p*r;
    ld ans = 0.0;
    ans += fs(r-1,s,p)*((r*p)/total);
    ans += fs(r,s-1,p)*((r*s)/total);
    ans += fs(r,s,p-1)*((s*p)/total);
    return dp[r][s][p] = ans;
}
// Paper
ld fp(int r, int s, int p) {
    if(p == 0 or r == 0) return 0.0;
    if(s == 0) return 1.0;
    if(dp[r][s][p] > -0.9){ return dp[r][s][p]; }
    ld total = r*s + s*p + p*r;
    ld ans = 0.0;
    ans += fp(r-1,s,p)*((r*p)/total);
    ans += fp(r,s-1,p)*((r*s)/total);
    ans += fp(r,s,p-1)*((s*p)/total);
    return dp[r][s][p] = ans;
}
int main() {
    ll r, s, p;
    cin>>r>>s>>p;
    memset(dp, -1.0, sizeof dp);
	ld ans_r = fr(r,s,p);
	memset(dp, -1.0, sizeof dp);
	ld ans_s = fs(r,s,p);
	memset(dp, -1.0, sizeof dp);
	ld ans_p = fp(r,s,p);
	cout<<fixed<<setprecision(12)<<ans_r<<" "<<ans_s<<" "<<ans_p; 
    return 0;
}