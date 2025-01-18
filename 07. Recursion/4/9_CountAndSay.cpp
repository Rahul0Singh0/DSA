// Leetcode 38
#include <bits/stdc++.h>
using namespace std;
// Time: O(2^N) and Space: O(N)
string countAndSay(int n) {
    if(n == 1) return "1";
    string s = countAndSay(n-1);
    string res = "";
    int freq = 1;
    for(int i = 0; i < s.size(); i++) {
        if(i+1 < s.size() && s[i] == s[i+1]) {
            freq++;
        } else {
            res += to_string(freq) + s[i];
            freq = 1;
        }
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    cout<<countAndSay(n)<<endl;
    string res = "1";
    while(--n > 0) {
        string next;
        for(int i = 0; i < res.size(); i++) {
            int freq = 1;
            while(i+1 < res.size() && res[i] == res[i+1]) {
                freq++;
                i++;
            }
            next += to_string(freq) + res[i];
        }
        res = move(next);
    }
    cout<<"\n"<<res<<endl;
    return 0;
}