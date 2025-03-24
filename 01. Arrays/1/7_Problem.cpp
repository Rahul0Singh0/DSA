/**
 * Find the last occurrence of x in the array
 */

#include <iostream>
using namespace std;

int main() {
    int x = 3;
    int arr[] = {5, 3, 2, 0, 6, 5, 3, 6};
    int n = 8;
    int res = -1;
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] == x) {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}