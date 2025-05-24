// Given a string consisting of lowercase English letters. return the character that is occurring most number of times.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char fun (string &str) {
        vector<int> freq(26, 0);
        for (char ch : str) {
            freq[ch - 'a']++;
        }

        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }
        }

        return maxChar;
    }
};

int main () {
    Solution s;
    string str;
    getline(cin, str);
    cout << s.fun(str) << endl;
    return 0;
}