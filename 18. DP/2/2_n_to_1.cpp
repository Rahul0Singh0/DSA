// Given a number 'n' you can perform any of the following operations on it some no. of times.
//  1 => reduce 'n' to 'n-1'
//  2 => if 'n' is divisible by 2, make it n/2
//  3 => if 'n' is divisible by 3, make it n/3
// find out in how many min. steps you can reduce n to 1
// https://www.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition0618/0
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int fun(int n) {
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    return 1+min({fun(n-1),(n%2==0) ? fun(n/2): INT_MAX, (n%3==0)?fun(n/3):INT_MAX}); 
}
vector<int> dp;
int ftd(int n) {
    if(n == 1) return 0;
    if(n == 2 or n == 3) return 1;
    if(dp[n] != -1) return dp[n];// nth state is precomputed
    // if dp[n] is -1, we need to compute first time this state
    return dp[n] = 1+min({fun(n-1),(n%2==0) ? fun(n/2): INT_MAX, (n%3==0)?fun(n/3):INT_MAX}); 
}
int fbu(int n) {
    dp.clear();
    dp.resize(n+1,-1);
    dp[1] = 0;
    dp[2] = dp[3] = 1;
    for(int i = 4; i <= n; i++) {
        dp[i] = 1 + min({dp[i-1], (i%2==0)?dp[i/2]:INT_MAX, (i%3==0)?dp[i/3]:INT_MAX});
    }
    return dp[n];
}
int main() {
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1005, -1);
    cout<<"\n"<<fbu(n)<<endl;
    return 0;
}