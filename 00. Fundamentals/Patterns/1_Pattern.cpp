/**
 * ****
 * ****
 * ****
 * ****
 */

#include <iostream>
using namespace std;
void f(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}
int main() {
    int n;
    cin>>n;
    f(n);
    return 0;
}