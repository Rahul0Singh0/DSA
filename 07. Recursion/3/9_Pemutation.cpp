// https://leetcode.com/problems/permutations/
// leetcode 46
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

// time : O(n*n!), space : O(n!)
// reduce this space by apply backtracking steps
void permutation(string input, string output) {
    if(input.size() == 0) {
        cout<<output<<"\n";
        return;
    }
    for(int i = 0; i < input.size(); i++) {
        char ch = input[i];
        string left = input.substr(0, i);
        string right = input.substr(i+1);
        string ros = left + right; // rest of string
        permutation(ros, output+ch);
    }
}

void f1(string str , int idx) {
    if(idx == str.size()-1) {
        cout<<str<<endl;
        return;
    }
    for(int i = idx; i < str.size(); i++) {
        swap(str[i], str[idx]);
        f1(str, idx+1);
        swap(str[i], str[idx]); // reverting back
    }
}

 void f(string &str, int i) {
    if(i == str.size()-1) {
        cout<<str<<"\n";
        return;
    }
    unordered_set<char> s;
    for(int idx = i; idx < str.size(); idx++) {
        if(s.count(str[idx])) continue;
        s.insert(str[idx]);
        swap(str[idx], str[i]);
        f(str, i+1);
        swap(str[idx], str[i]); // reverting step of backtracking
    }
}

void f(string str) {
    sort(str.begin(), str.end());
    do {
        cout<<str<<endl;
    } while(next_permutation(str.begin(), str.end()));
}

int main() {
    string str;
    cin>>str;
    // permutation(str, "");
    f1(str, 0);
    return 0;
}