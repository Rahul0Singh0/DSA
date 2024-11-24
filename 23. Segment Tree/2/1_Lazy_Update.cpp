#include <iostream>
#include <vector>
using namespace std;

vector<int> lazy;
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
    st[i] = st[2*i+1] + st[2*i+2]; 
}

int l, r;

// Time : O(log(n))
int getSum(int i, int lo, int hi) {
    // check for pending lazy updates
    if(lazy[i] != 0) {
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize * lazy[i];
        if(lo != hi) { // send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l > hi or r < lo) return 0;
    if(lo >= l and hi <= r) return st[i];
    int mid = lo + (hi - lo) / 2;
    int leftSum = getSum(2*i+1, lo, mid);
    int rightSum = getSum(2*i+2, mid+1, hi);
    return leftSum + rightSum;
}

void updateRange(int i, int lo, int hi, int value) {
    // check for pending lazy updates
    if(lazy[i] != 0) {
        int rangeSize = hi - lo + 1;
        st[i] += rangeSize * lazy[i];
        if(lo != hi) { // send lazy to left and right child
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(l > hi or r < lo) return; // out of range
    if(lo >= l and hi <= r) {
        // update entire [lo, hi]
        int rangeSize = hi-lo+1;
        st[i] += rangeSize*value;
        if(lo != hi) { // send lazy to left and right child
            lazy[2*i+1] += value;
            lazy[2*i+2] += value;
        }
        return;
    }
    // Overlap
    int mid = lo + (hi-lo)/2;
    updateRange(0, lo, mid, value);
    updateRange(0, mid+1, hi, value);
    st[i] = st[2*i+1] + st[2*i+2];
}

int main() {
    int arr[] = {1,4,2,8,6,4,9,3}; // 0 to 7
    int n = sizeof arr / sizeof arr[0];
    st.resize(4*n);
    lazy.resize(4*n, 0);
    buildTree(arr, 0, 0, n-1);
    int q;
    cin>>q;
    while(q--) {
        cout<<"\nEnter the range: ";
        cin>>l>>r;
        int choice;
        cout<<"\nWant to sum(1) or update(0) : ";
        cin>>choice;
        int incr;
        if(choice) cout<<"\n"<<getSum(0,0,n-1);
        else cout<<"\nEnter value to add : ", cin>>incr, updateRange(0,0,n-1,incr);
    }
    return 0;
}