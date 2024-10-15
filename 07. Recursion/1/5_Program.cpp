// Make a function which calculate 'a' raised to the power 'b' using recursion
#include <iostream>
using namespace std;

int f(int a, int b) {
    if(b == 0) return 1;
    return a * f(a, b-1);
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<f(a,b);
    return 0;
}