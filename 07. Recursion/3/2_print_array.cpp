// Printing Array's elements using recursion
#include <iostream>
#include <climits>
using namespace std;
void f(int *A, int i, int n) {
    if(i >= n) return;
    cout<<A[i]<<" ";
    f(A, i+1, n);
}
int ans = INT_MIN;
int f1(int *A, int i, int n) {
    if(i >= n) return ans;
    ans = max(ans, A[i]);
    f1(A, i+1, n);
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++) cin>>A[i];
    f(A, 0, n);
    cout<<f1(A,0, n);
    return 0;
}