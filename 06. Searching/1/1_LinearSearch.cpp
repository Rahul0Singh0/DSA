#include <iostream>
using namespace std;
// Time: O(N), Space: O(1)
int main() {
    int arr[] = {5,2,67,8,2,6,87};
    int n = 7;
    int target = 67;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(target == arr[i]) {
            cout<<i<<endl;
            flag = true;
            break;
        }
    }
    if(flag) cout<<"Found";
    else cout<<"Not Found";
    return 0;
}