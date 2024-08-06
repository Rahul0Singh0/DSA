#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // Two pointer
    // Time : O(n*log n), Space : O(sorting)
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int boat = 0;
        while(i <= j) {
            // best case: allocate a boat to the pair 
            if(people[i] + people[j] <= limit) {
                i++;j--;boat++;
            }
            // worst case: allocate a boat to the heaviest
            else {
                j--;
                boat++;
            }
        }
        return boat;
    }
};
int main() {
    Solution s;
    vector<int> people{2,3,7,8,10};
    int limit = 10;
    cout<<s.numRescueBoats(people, limit);
    return 0;
}