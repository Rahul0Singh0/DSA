/* https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /* using counting or bucket sort to achieve greedy approach */
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int bucket[51] = {0};
        for (const int c: capacity) {
            bucket[c]++;
        }
        int totalApple = std::accumulate(apple.begin(), apple.end(), 0);
        int totalUsedBucket = 0;
        for (int i = 50; i >= 1; i--) {
            while (bucket[i]) {
                totalApple -= i;
                totalUsedBucket += 1;
                bucket[i] -= 1;
                if (totalApple <= 0) {
                    return totalUsedBucket;
                } 
            }
        }
        return totalUsedBucket;
    }
    
    int minimumBoxes1(vector<int>& apple, vector<int>& capacity) {
        int sum = std::accumulate(apple.begin(), apple.end(), 0);
        std::sort(capacity.begin(), capacity.end(), std::greater<int>());

        int total = 0;
        int totalCapacity = 0;
        for(const int& c : capacity) {
            totalCapacity += c;
            total += 1;
            if(totalCapacity >= sum) {
                return total;
            } 
        }
        return -1;
    }
};