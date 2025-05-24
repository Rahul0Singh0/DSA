// Leetcode 242
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// Using unordered_map: Time Complexity: O(n), Space Complexity: O(n)
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mp1;
        for(int i = 0; i < s.size(); i++) {
            mp1[s[i]]++;
        }
        for(int i = 0; i < s.length(); i++) {
            char ch = t[i];
            if(mp1.find(ch) != mp1.end()) {
                mp1[ch]--;
                if(mp1[ch] == 0) mp1.erase(ch);
            }
            else return false;
        }
        if(mp1.size() > 0) return false;
        return true;
    }

    bool isAnagram2(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }

    bool isAnagram3(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main () {
    Solution s;
    string str1, str2;
    cin >> str1 >> str2;
    cout << s.isAnagram(str1, str2);
    cout << endl;
    cout << s.isAnagram2(str1, str2);
    cout << endl;
    cout << s.isAnagram3(str1, str2);
    return 0;
}