// Leetcode 60
#include <bits/stdc++.h>
using namespace std;
string fun(int n, int k) {
    vector<string> res;
    string str;
    for(int i = 1; i <= n; i++) str += to_string(i);
    sort(str.begin(), str.end());
    do {
        cout<<str<<endl;
        res.push_back(str);
    } while(next_permutation(str.begin(), str.end()));
    
    return res[k-1];
}
string getPermutation(int n, int k) {
    
}
int main() {
    int n,k;
    cin>>n>>k;
    cout<<fun(n,k);
    return 0;
}