#include <iostream>
using namespace std;

// Time: O(log(N))
int f(int x, int n) {
    if(n == 1) return x;
    // int ans = f(x, n/2);
    if(n%2 == 0) return f(x, n/2) * f(x, n/2);
    else return x * f(x, n/2) * f(x, n/2);
}

int main() {
    int x, n;
    cin>>x>>n;
    cout<<f(x, n)<<" ";
    return 0;
}