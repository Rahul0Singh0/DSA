// leetcode 22
// generate parentheses
#include <bits/stdc++.h>
using namespace std;
// void generate(string str, int open, int close, int n) {
//     if(close == n) {
//         cout<<str<<endl;
//         return;
//     }
//     if(open < n) generate(str+'(', open+1, close, n);
//     if(close < open) generate(str+')', open, close+1, n);
// }
void generate(int n) {
    function<void(int, int, string)> dfs = [&](int open, int close, string str) {
        if(open > n || close > n || open < close) return;
        if(close == n) {
            cout<<str<<endl;
            return;
        }
        dfs(open+1, close, str+'(');
        dfs(open, close+1, str+')');
    };
    dfs(0,0,"");
}
int main() {
    int n;
    cin>>n;
    // generate("",0,0,n);
    generate(n);
    return 0;
}