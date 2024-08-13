#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int fun(vector<int>& v) {
        int cn = 0, cp = 0, cz = 0; // counts negative, positive and zeros
        int product_pos = 1, product_neg = 1;
        int largestNeg = INT_MIN;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == 0) cz++;
            else if(v[i] < 0) {
                cn++;
                largestNeg = max(largestNeg, v[i]);
                product_neg *= v[i];
            }
            else {
                cp++;
                product_pos *= v[i];
            }
        }
        if(cn == 0) {
            if(cz > 0) return 0;
            else {
                auto it = min_element(v.begin(), v.end());
                return *it;
            }
        }
        else {
            if(cn%2 == 0) {
                return (product_neg/largestNeg)*product_pos;
            }
            else {
                return product_neg*product_pos;
            }
        }
    }
};
int main() {
    vector<int> v{-9,0,-4,-3};
    Solution s;
    cout<<"\n"<<s.fun(v);
}