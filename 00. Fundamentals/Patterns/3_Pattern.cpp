/**
 * *
 * **
 * ***
 * ****
 */

#include <iostream>
using namespace std;
void pattern1(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout<<"*";
        }
        cout<<"\n";
    }
}

/**
 * ****
 * ***
 * **
 * *
 */

void pattern2(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i+1; j++) {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    cin>>n;
    pattern1(n);
    return 0;
}