// Leetcode 480
#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

bool isBalanced(int x, int y) {
    return (x == y) || (x+1 == y);
}

double getMedian(priority_queue<int>&left, priority_queue<int, vector<int>,
 greater<int>>&right, int x, int y) {
    int totalSize = x + y;
    if(totalSize % 2 != 0) // odd 
       return right.top();
    else // even
       return (left.top() + right.top()) /2.0;
}


vector<double> sliding_median(vector<int>& arr, int n, int k) {
    priority_queue<int> left;//max
    priority_queue<int, vector<int>, greater<int>> right;// min
    unordered_map<int,int> mp;
    int x = 0, y = 0;
    right.push(arr[0]); // indexes
    for(int i = 0; i < k; i++) {
        int curr = arr[i];
        double med = getMedian(left, right, x, y);
        if(curr < med) {
            //  go left
            left.push(curr);
            x++;
            if(!isBalanced(x, y)) { // inbalanced
                int toBeRemoved = left.top();
                left.pop();
                right.push(toBeRemoved);
                x--; y++;
            } 
        }
        else {
            // go right
            right.push(curr);
            y++;
            if(!isBalanced(x,y)) { // inbalanced
                int toBeRemoved = right.top();
                right.pop();
                left.push(toBeRemoved);
                y--; x++;
            }
        }
    }
    double m = getMedian(left, right, x, y); // answer of first window
    vector<double> result;
    result.push_back(m);

    for(int i = k; i < n; i++) {
        int newElementIndex = i;
        int oldElementToBeDeleted = i - k;
        double med = getMedian(left, right, x, y);
        if(arr[newElementIndex] > med) {
            // go right
            right.push(arr[newElementIndex]);
            y++;
            if(!isBalanced(x, y)) { // inbalanced
                int toBeRemoved = left.top();
                left.pop();
                right.push(toBeRemoved);
                x--; y++;
            }
        }
        else {
            // go left
            left.push(arr[newElementIndex]);
            x++;
            if(!isBalanced(x,y)) { // inbalanced
                int toBeRemoved = right.top();
                right.pop();
                left.push(toBeRemoved);
                y--; x++;
            }
        }

        mp[arr[oldElementToBeDeleted]] = oldElementToBeDeleted;

        while(!left.empty() && mp[left.top()]) {
            mp.erase(left.top());
            left.pop();
            x--;
            if(!isBalanced(x, y)) {
                int toBeRemoved = right.top();
                right.pop();
                left.push(toBeRemoved);
                y--; x++;
            }
        }
        while(!right.empty() && (mp[right.top()])) {
            mp.erase(right.top());
            right.pop();y--;
            if(!isBalanced(x, y)) { // inbalanced
                int toBeRemoved = left.top();
                left.pop();
                right.push(toBeRemoved);
                x--; y++;
            }
        }
        result.push_back(getMedian(left, right, x, y));
    }
    return result;
}
int main() {
    // Fast IO
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // Fast IO
    int t = 1;
    int n;
    int k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    vector<double> ans = sliding_median(arr, n, k);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<"\n";
    }
    return 0;
}