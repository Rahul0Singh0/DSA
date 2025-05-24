/**
 * Input a string and return the number of times the neighboring characters
 * are different from each other. 
 * For example, in the string "aabbcc", the neighboring characters are:
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f (string &str) {
        int cnt = 0;
        for (int i = 1; i < str.size(); i++) {
            if (str[i-1] != str[i]) cnt++;
        }
        return cnt;
    }
    
    int countRecursive(const string& str, int idx) {
        if (idx >= str.length() - 1) return 0;
        return (str[idx] != str[idx + 1]) + countRecursive(str, idx + 1);
    }
};

int main () {
    Solution s;
    string str;
    getline(cin, str);
    cout << s.f(str);
    cout << endl;
    cout << s.countRecursive(str, 0);
    return 0;
}