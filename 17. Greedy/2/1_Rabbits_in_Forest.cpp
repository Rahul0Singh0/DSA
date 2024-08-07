// Leetcode 781
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int result = 0;
        for(int i = 0; i < answers.size(); i++) {
            if(!mp[answers[i]+1]) {
                // We started colour group
                result += answers[i] + 1;
                if(answers[i] == 0) continue;
                mp[answers[i]+1] = 1;
            }
            else {
                mp[answers[i]+1]++;
                int key = answers[i]+1;
                int val = mp[key];
                if(key == val) {
                    // we found all the rabbits of the group 
                    // eliminate the group
                    mp.erase(key);
                }
            }
        }
        return result;
    }
};
int main() {
    vector<int> v = {1,0,1,0,0};
    Solution s;
    cout<<endl<<s.numRabbits(v);
}