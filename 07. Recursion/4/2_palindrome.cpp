#include <bits/stdc++.h>
using namespace std;
bool palindrome(string str, int lo, int hi) {
    if(lo > hi) return true;
    if(str[lo] != str[hi]) return false;
    return palindrome(str, lo + 1, hi - 1);
}
int main() {
    string str;
    cin>>str;
    cout<<palindrome(str, 0, str.size()-1);
    return 0;
}