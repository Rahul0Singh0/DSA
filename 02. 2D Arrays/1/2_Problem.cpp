/**
 * WAP to store roll number and marks obtained by 4 students side by side in a matrix
 */
#include <iostream>
using namespace std;

int main() {
    int arr[4][2]; // row -> student and col -> marks
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cin>>arr[i][j];
        }
    }
}