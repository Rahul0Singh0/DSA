// Generate all binary strings of length n without consecutive 1's
#include <bits/stdc++.h>
using namespace std;
// void binaryNumber(string binary, int n) {
//     if(binary.size() == n) {
//         cout<<binary<<endl;
//         return;
//     }
//     binaryNumber(binary+'0', n);
//     if(binary[binary.size()-1] != '1') 
//         binaryNumber(binary+'1', n);
// }
void binaryNumber(int n) {
    function<void(string)> dfs = [&](string binary) {
        if(binary.size() == n) {
            cout<<binary<<endl;
            return;
        }
        dfs(binary+'0');
        if(binary[binary.size()-1] != '1')
           dfs(binary+'1');
    };
    dfs("");
}
int main() {
    int n;
    cin>>n;
    // binaryNumber("", n);
    binaryNumber(n);
    return 0;
}