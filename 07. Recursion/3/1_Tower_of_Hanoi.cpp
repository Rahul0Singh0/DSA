#include <iostream>
using namespace std;
void f(int n, char s, char h, char d) {
    if(n == 0) return;
    f(n-1, s, d, h);
    cout<<s<<"->"<<d<<endl;
    f(n-1, h, s, d);
}
int main() {
    int n;
    cin>>n;
    f(n, 'a', 'b', 'c');
    return 0;
}