// Peak Element
#include <bits/stdc++.h>

int fun(std::vector<int>& arr) {
    int l = 0, r = arr.size();
    while(l < r) {
        const int mid = (l + r) >> 1;
        if(arr[mid] > arr[mid+1]) r = mid;
        else l = mid + 1;
    }
    return l;
}