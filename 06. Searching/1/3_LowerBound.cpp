#include <bits/stdc++.h>
using namespace std;
int LowerBound(int arr[], int n, int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << LowerBound(arr, n, 3) << endl;
    cout<<lower_bound(arr,arr+n,3)-arr<<endl;
    return 0;
}