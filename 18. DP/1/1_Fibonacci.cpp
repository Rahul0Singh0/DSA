// Leetcode 509
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // Bruteforce
    int fibonacci(int n) {
        if(n == 0 || n == 1) return n;
        return fibonacci(n-1) + fibonacci(n-2); 
    }
    // Memoization + recursion = DP 
    // TOP DOWN APPROACH
    int fibo(int n, vector<int>& dp) {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    }
    // Iteration (Bottom to up)
    int fib(int n) {
        int dp[n+1];
        dp[0] = 0;
        if(n >= 1) dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
int main() {
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    Solution s;
    cout<<"\n"<<s.fibonacci(n)<<endl;
    cout<<"\n"<<s.fibo(n, dp)<<endl;
    cout<<"\n"<<s.fib(n)<<endl;
}