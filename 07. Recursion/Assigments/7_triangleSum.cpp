#include <bits/stdc++.h>
using namespace std;
void fun(vector<int>& v) {
    if(v.size() == 0) return;
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i = 1; i < v.size(); i++) {
        v[i-1] = v[i-1] + v[i];
    } 
    v.pop_back();
    fun(v);
}
int main() {
    vector<int> v{5, 4, 3, 2, 1};
    fun(v);
    return 0;
}