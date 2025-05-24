// Given a sentence, split every single word of the sentence and print in a new line.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void fun (string &sentence) {
        istringstream iss(sentence);
        string word;
        while (iss >> word) {
            cout << word << endl;
        }
    }

    void fun2 (string &sentence) {
        stringstream ss(sentence);
        string word;
        while (getline(ss, word, ' ')) {
            cout << word << endl;
        }
    }

    void fun3 (string &sentence) {
        size_t start = 0, end;
        while (end = sentence.find(' ', start) != string::npos) {
            cout << sentence.substr(start, end - start) << endl;
            start = end + 1;
        }
        cout << sentence.substr(start) << endl; // Print the last word
    }
};

int main () {
    Solution s;
    string sentence;
    getline(cin, sentence);
    s.fun3(sentence);
    return 0;
}