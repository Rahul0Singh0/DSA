#include <iostream>
using namespace std;

// Parameterized
void f(int &sum, int n) {
    if(n == 0)return;
    sum += n;
    return f(sum, n-1);
} 

// return type
int f1(int n) {
    if(n == 0) return 0;
    return n + f1(n-1);
}

int main() {
    int n;
    cin>>n;
    int sum = 0;
    f(sum, n);
    cout<<sum<<"\n";
    cout<<f1(n)<<"\n";
    return 0;
}