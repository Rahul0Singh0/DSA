// string compression
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int ans = 0;
    for (int i = 0; i < chars.size();) {
        const char letter = chars[i];
        int count = 0;
        while (i < chars.size() && chars[i] == letter) {
            ++count;
            ++i;
        }
        chars[ans++] = letter;
        if (count > 1)
            for (const char c : to_string(count))
                chars[ans++] = c;
    }
    cout<<ans<<endl;
    cout<<chars<<endl;
    return 0;
}