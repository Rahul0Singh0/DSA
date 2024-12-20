// Write a function to calculate the nth fibonacci number using recursion
#include <iostream>
using namespace std;

// O(N^2)
int f(int n) {
    if(n == 1 || n == 2) return 1;
    return f(n-1) + f(n-2);
}

int main() {
    int n;
    cin>>n;
    cout<<f(n)<<"\n";
    return 0;
}