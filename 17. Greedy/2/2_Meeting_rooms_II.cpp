// Leetcode 253 and coding ninja
#include <bits/stdc++.h> 
using namespace std;
int minRooms(vector<vector<int>> intervals) {
    // Write your code here
    vector<int> start;
    vector<int> ending;
    for(int i = 0; i < intervals.size(); i++) {
        start.push_back(intervals[i][0]);
        ending.push_back(intervals[i][1]);
    }
    sort(start.begin(), start.end());
    sort(ending.begin(), ending.end());
    int ans = 0; int rooms = 0;
    int i = 0, j = 0;
    // Merging technique use(two pointer)
    while(i < start.size() && j < ending.size()) {
        if(start[i] < ending[j]) {
            // a meeting is starting
            rooms++; 
            ans = max(ans, rooms);
            i++;
        }
        else if(start[i] > ending[j]) {
            rooms--;
            j++;
        }
        else {
            if(rooms == 0) // special condition for special case
               rooms++;
            ans = max(ans, rooms);
            i++;j++;
        }
    }
    return ans;
}
int main() {
    // vector<vector<int>> v{{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
    vector<vector<int>> v{{1000,1000},{1000,1000}}; // special case of coding ninja
    cout<<"\n"<<minRooms(v);
}