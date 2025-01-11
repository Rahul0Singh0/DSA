#include <iostream>
#include <vector>
using namespace std;
void f(vector<int>& arr, vector<int> subArray,int idx) {
    if(idx == arr.size()) {
        if(subArray.size() == 0) return;
        for(int i = 0; i < subArray.size(); i++) {
            cout<<subArray[i];
        }
        cout<<endl;
        return;
    }
    f(arr, subArray, idx+1);
    if(subArray.size() == 0 || subArray[subArray.size()-1] == arr[idx-1])
       subArray.push_back(arr[idx]);
    f(arr, subArray, idx+1); 
}
int main() {
    vector<int> arr{1, 2, 3};
    f(arr, {}, 0);
    // int arr[] = {1, 2, 3, 4};
    // for(int i = 0; i < 4; i++) {
    //     for(int j = i; j < 4; j++) {
    //         for(int k = i; k <= j; k++) {
    //             cout<<arr[k];
    //         }
    //         cout<<endl;
    //     }
    // }    
    return 0;
}