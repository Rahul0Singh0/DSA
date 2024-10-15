#include <iostream>
using namespace std;
// Print 1 to n (extra parameter)
void f(int i, int n) {
    if(i > n) return;
    cout<<i<<" ";
    f(i+1, n);
}

// after recursive call
void f1(int n) {
    if(n == 0) return;
    f1(n-1);
    cout<<n<<" ";
}

int main() {
    int n;
    cin>>n;
    f(1, n);
    cout<<endl;
    f1(n);
    return 0;
}