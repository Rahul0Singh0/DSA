// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
  public:
    bool static cmp(Item i1, Item i2) {
        double r1 = (i1.value*1.0)/(i1.weight*1.0);
        double r2 = (i2.value*1.0)/(i2.weight*1.0);
        return r1 > r2;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        sort(arr, arr+n, cmp);
        double result = 0.0;
        for(int i = 0; i < n; i++) {
            if(arr[i].weight <= w) {
                result += arr[i].value;
                w -= arr[i].weight;
             }
             else { // remaining space in knapsack
                result += ((arr[i].value*1.0)/(arr[i].weight*1.0))*w;
                w = 0;
                break;
             }
        }
        return result;
    }
};

int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout<<endl<<(double)ans<<endl;
   return 0;
}