/**
 * Input a string of length n & reverse the first half of it.
 */

#include <iostream>
using namespace std;

int main () {
    string str;
    getline(cin, str);
    int half = str.length() / 2;
    // This will only using auxiliary space of O(n) for the reversed string.
    // string firstHalf = str.substr(0, half);
    // string secondHalf = str.substr(half);
    // string reversedFirstHalf = string(firstHalf.rbegin(), firstHalf.rend());
    // str = reversedFirstHalf + secondHalf;

    // Two pointer approach to reverse the first half of the string in place.
    int l = 0, r = half - 1;
    while (l <= r) {
        swap(str[l], str[r]);
        l++;
        r--;
    }
    cout << str << endl;
    return 0;
}