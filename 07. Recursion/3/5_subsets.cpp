#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> res;
void f(string& str, string subset, int i) {
    if(i == str.size()) {
        res.push_back(subset);
        return;
    }
    f(str, subset, i+1);
    f(str, subset+str[i], i+1);
}

void f1(string str, string subset, bool flag) {
    if(str.length() == 0) {
        res.push_back(subset);
        return; 
    }
    char ch1 = str[0];
    char ch2 = str[1];
    if(ch1 == ch2) {
        if(flag) f1(str.substr(1), subset+ch1, true);
        f1(str.substr(1), subset, false);
    } else {
        if(flag) f1(str.substr(1), subset+ch1, true);
        f1(str.substr(1), subset, true);
    }
}

void dfs(string str, string subset, int idx) {
    res.push_back(subset);
    for(int i = idx; i < str.size(); i++) {
        subset.push_back(str[i]);
        dfs(str, subset, i+1);
        subset.pop_back();
    }
}

int main() {
    string str;
    cin>>str;
    res.clear();
    // f1(str, "", true);
    dfs(str, "", 0);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}