/**
 * WAP to print sum of all the elements of a 2D matrix
 */
#include <iostream>
using namespace std;

int main() {
    int arr[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin>>arr[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
    cout<<sum<<endl;
    return 0;
}