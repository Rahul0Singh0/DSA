#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr) {
    int l = 0, r = arr.size()-1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1]) {
            return arr[mid];
        } else if(arr[mid] < arr[mid+1]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}
int main() {
    vector<int> arr{1,3,5,4,3,2,0};
    for(int i = 0; i < arr.size()-1; i++) {
        if(arr[i] >= arr[i+1]) {
            cout<<arr[i]<<endl;
            break;
        }
    }
    cout<<endl<<fun(arr);
    return 0;
}