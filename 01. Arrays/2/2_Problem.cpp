#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5;
    int res[n];
    int i = 0, j = n-1;
    while(i < n) {
        res[i++] = arr[j--];
    }
    i = 0;
    while(i < n) {
        cout<<res[i++]<<" ";
    }
    return 0;
}