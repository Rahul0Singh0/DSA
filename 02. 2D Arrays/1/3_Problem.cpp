/**
 * WAP to find the largest element of a given 2D array of integers
 */
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin>>arr[i][j];
        }
    }
    int mx = INT_MIN;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mx = max(mx, arr[i][j]);
        }
    }
    cout<<mx<<endl;
    return 0;
}