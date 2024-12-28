// leetcode 78
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

int main() {
    string str;
    cin>>str;

    f(str, "", 0);
    for(int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}