/**
 * Write a program to reverse the array without without using extra array.
 */
#include <iostream>
int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int i = 0, j = n-1;
    while(i < j) {
        std::swap(arr[i++], arr[j--]);
    }
    for(int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}