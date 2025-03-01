/**
 * 1
 * 12
 * 123
 * 1234
 */

#include <iostream>
using namespace std;
void pattern1(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<j;
        }
        cout<<"\n";
    }
}

/**
 * 1234
 * 123
 * 12
 * 1
 */

void pattern2(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout<<j;
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    pattern1(n);
    pattern2(n);
    return 0;
}