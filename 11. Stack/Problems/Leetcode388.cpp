// https://leetcode.com/problems/longest-absolute-file-path/description/
// TODO
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        int i = 0, n = input.size();
        int ans = 0;
        stack<int> st;
        while (i < n) {
            int ident = 0;
            for (; input[i] == '\t'; ++i) {
                ++ident;
            }

            int cur = 0;
            bool isFile = false;
            for (; i < n && input[i] != '\n'; ++i) {
                ++cur;
                if (input[i] == '.') {
                    isFile = true;
                }
            }
            ++i;

            while (!st.empty() && st.size() > ident) {
                st.pop();
            }

            if (st.size() > 0) {
                cur += st.top() + 1;
            }

            if (!isFile) {
                st.push(cur);
                continue;
            }

            ans = max(ans, cur);
        }
        return ans;
    }
};