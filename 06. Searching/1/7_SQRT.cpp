// Leetcode 69
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(ll x) {
    int lo = 0, hi = x; 
    int ans = INT_MIN;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        ll sq = mid * mid;
        if(sq == x) {ans = max(ans, mid); break;}
        else if(sq < x) ans = max(ans, mid), lo = mid + 1;
        else hi = mid - 1;
    }
    return ans;
}
int main() {
    ll x;
    cin >> x;
    for(ll i = 0; i <= x; i++) {
        if(i * i == x) {
            cout << i;
            break;
        } else if(i * i > x) {
            cout << i - 1;
            break;
        }
    }
    cout<<endl<<f(x);
    return 0;
}