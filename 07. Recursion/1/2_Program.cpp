// Print n to 1
#include <iostream>
using namespace std;

void f(int n) {
    if(n == 0) return;
    cout<<n<<" ";
    f(n-1);
}

int main() {
    int n;
    cin>>n;
    f(n);
    return 0;
}