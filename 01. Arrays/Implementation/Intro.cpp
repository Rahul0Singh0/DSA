#include <bits/stdc++.h>
using namespace std;

int main() {
    // int arr[10]; // static array
    // int *Arr = new int[5]; // dynamic array
    // for(int i = 0; i < 5; i++) cin>>Arr[i];
    // int newSize = 10;
    // int *newArr = new int[newSize];
    // // copy data from old array to newArray
    // for(int i = 0; i < 5; i++) newArr[i] = Arr[i];
    // // Initiale initital values
    // for(int i = 5; i < newSize; i++) newArr[i] = 0;
    // delete[] Arr;
    // Arr = newArr;
    // for(int i = 5; i < newSize; i++) cin>>newArr[i];
    // delete[] Arr; // clean up manually
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    cout<<v.size()<<" "<<v.capacity()<<endl;
    v.resize(15, 10);
    cout<<v.size()<<" "<<v.capacity()<<endl;


    return 0;
}