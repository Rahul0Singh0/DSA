#include <iostream>
#include <climits>
using namespace std;
int mx = INT_MIN;
int f(int arr[], int i, int n) {
    if(i >= n) return mx;
    return mx = max(arr[i], f(arr, i+1, n));
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];
    cout<<f(arr, 0, n);
    return 0;
}