#include <iostream>
#include <vector>
using namespace std;

vector<int> st; // segment tree

// building segment tree
// Time : 4*n = O(n)
void buildTree(int *arr, int i, int lo, int hi) {
    if(lo == hi) { // base case
        st[i] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo) / 2;
    buildTree(arr, 2*i+1, lo, mid); // left subTree
    buildTree(arr, 2*i+2, mid+1, hi); // right subTree
    st[i] = max(st[2*i+1], st[2*i+2]); 
}

int l, r;

// Time : O(log(n))
int getMax(int i, int lo, int hi) {
    if(l > hi or r < lo) return INT_MIN;
    if(lo >= l and hi <= r) return st[i];
    int mid = lo + (hi - lo) / 2;
    int leftMax = getMax(2*i+1, lo, mid);
    int rightMax = getMax(2*i+2, mid+1, hi);
    return max(leftMax, rightMax);
}

int main() {
    int arr[] = {1,4,2,8,6,4,9,3}; // 0 to 7
    int n = sizeof arr / sizeof arr[0];
    st.resize(4*n);
    buildTree(arr, 0, 0, n-1);
    int q;
    cin>>q;
    while(q--) {
        cout<<"\nEnter the range: ";
        cin>>l>>r;
        cout<<"\n"<<getMax(0, 0, n-1);
    }
}