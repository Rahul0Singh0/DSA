#include <iostream>
using namespace std;
int main() {
    int arr[][3] ={12,34,45,65,23,45};
    for(auto a: arr) {
        for(int i = 0; i < 3; i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}