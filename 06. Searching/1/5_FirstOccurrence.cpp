/**
 * Given a sorted array of n elements and target 'x'. Find the first occurrence of 'x' in
 * the array. If 'x' is not present, return -1.
 */
#include <bits/stdc++.h>
using namespace std;
int f(vector<int>& arr, int x) {
    int n = arr.size();
    int lo = 0, hi = n-1;
    int ans = -1;
    while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == x) {
            ans = mid;
            hi = mid - 1;
        } else if(arr[mid] > x) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int main() {
    vector<int> arr{1,2,2,3,3,3,3,3,4,4,5,8,9};
    int x = 3;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == x) {
            cout<<i<<endl;
            break;
        }
    }
    cout<<f(arr, x);
    return 0;
}