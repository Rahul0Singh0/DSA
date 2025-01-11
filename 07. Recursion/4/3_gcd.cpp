#include <iostream>
using namespace std;
// time : O(log(a+b))
int gcd(int a, int b) {
    if(a%b == 0) return b;
    gcd(b, a%b);
}
int f(int a, int b) {
    for(int i = min(a, b); i >= 2; i--) {
        if(a%i == 0 && b%i == 0) return i;
    }
    return 1;
}
int main() {
    int a, b;
    cin>>a>>b;
    cout<<gcd(a, b);
    cout<<"\n"<<f(a,b);
    return 0;
}