// Kth Symbol in Grammar
// Leetcode 779
#include <bits/stdc++.h>
#include <bitset>
using namespace std;
int kthGrammar(int N, int K) {
    if(N == 1) return 0;
    if(K % 2 == 0) return !kthGrammar(N-1, K/2);
    else return kthGrammar(N-1, (K+1)/2);
}
int fun(int n, int k) {
    if(n == 1) return 0;
    int mid = (1<<(n-2)); // mid 
    if(k <= mid) return fun(n-1, k);
    // else return 1-fun(n-1, k-mid);
    else return !fun(n-1, mid-k);
}
int bitManipulation(int n,int k) {
    // return __builtin_popcount(k-1)%2;
    return __builtin_popcount(k-1)&1;
}
int main() {
    int N = 2, K = 2;
    cout<<fun(N, K)<<endl;
    int res = 0;
    while(K > 1) {
        if(K%2 == 0) // second half
           res = 1-res;
        K = (K+1)/2;
    }
    cout<<res;
    return 0;
}