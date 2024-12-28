// Remove all occurrences of a given char from a string.
// String: "abac", ch = 'a'
// Output: "bc"
#include <iostream>
#include <string>
using namespace std;
string f(string& str, char ch) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == ch) {
            str.erase(i, 1);
        }
    }
    return str;
}
string fun(string& str, char ch, int i) {
    if(i >= str.size()) {
        return str;
    }
    if(str[i] == ch) {
        str.erase(i, 1);
    }
    return fun(str, ch, i+1);
}
string fun1(string& str, string& res, char ch) {
    if(str.size() == 0) {
        return res;
    } 
    if(str.front() != ch) {
        res += str.front();
    }
    str.erase(0, 1);
    return fun1(str, res, ch);
}
string f1(string& str, char ch) {
    // return fun(str, ch, 0);
    string res = "";
    fun1(str, res, ch);
    return res;
}
int main() {
    string str;
    char ch;
    cin>>str;
    cin>>ch;
    cout<<endl<<f1(str, ch);
}