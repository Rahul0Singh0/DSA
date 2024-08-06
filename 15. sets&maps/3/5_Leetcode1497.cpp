#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int e : arr) {
            e = ((e%k)+k)%k;
            mp[e]++;
        }
        // if not even freq of zero
        if(mp.find(0) != mp.end()) { // zero is present
            if(mp[0]%2 != 0) return false;
            mp.erase(0);
        }
        for(auto x : mp) {
            int a = x.first;
            int rem = k - a;
            if(mp.find(rem) == mp.end()) return false;
            if(mp[a] != mp[rem]) return false;
        }
        return true;
    }
};
int main() {
    vector<int> v;
    
}