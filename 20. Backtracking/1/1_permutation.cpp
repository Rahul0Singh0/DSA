// leetcode 46
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
// pass by value means every calls create new strings and copy data
// for big test cases populates in the memory
// wastage of memory/space
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
// pass by reference and swapping method use
// swapping method work as reverting step of backtracking
// "aba" problem arise that repitition of subproblem calls
// void f(string &str, int i) {
//     if(i == str.size()-1) {
//         cout<<str<<"\n";
//         return;
//     }
//     for(int idx = i; idx < str.size(); idx++) {
//         swap(str[idx], str[i]);
//         f(str, i+1);
//         swap(str[idx], str[i]); // reverting step of backtracking
//     }
// }
// to solve above problem is add on pruning irrelevant calls 
// this is step of backtracking
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
int main() {
    // permutation("abc", "");
    string str;
    cin>>str;
    f(str, 0);
    return 0;
}