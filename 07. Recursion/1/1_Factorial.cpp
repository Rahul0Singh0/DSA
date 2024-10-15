#include <iostream>
using namespace std;

int fi(int n) {
    int f = 1;
    for(int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

int fr(int n) {
    if(n == 0) return 1;
    return n * fr(n-1);
}

int main() {
    int n;
    cin>>n;
    cout<<"\n"<<fr(n);
    cout<<"\n"<<fi(n);
    return 0;
}