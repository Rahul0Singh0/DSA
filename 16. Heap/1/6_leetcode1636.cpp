// Sort array by increasing frequency 1636
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    typedef pair<int,int> p; // <freq, ele>
    vector<int> increasingFreq(vector<int>& arr) {
        
    }
};
int main() {
    vector<int> v;
    int n;
    std::cin>>n;
    for(int i = 0; i < n; i++) {
        int e;
        std::cin>>e;
        v.push_back(e);
    }
    Solution s;
    vector<int> ans = s.increasingFreq(v);
    for(int i = 0; i < ans.size(); i++)
        std::cout<<ans[i]<<" ";
    return 0;
}