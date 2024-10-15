#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // step 1: reverse each row (horizontal flip)
        for(int i = 0; i < image.size(); i++) {
            reverse(image[i].begin(), image[i].end());
        }
        // step 2: invert an image
        for(int i = 0; i < image.size(); i++) {
            for(int j = 0; j < image[i].size(); j++) {
                image[i][j] = image[i][j] ? 0 : 1;
            }
        }
        return image;
    }
};