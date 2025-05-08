/**
 * Input a string of length greater than 5 and reverse the string from position
 * 2 to 5 using inbuilt function.
 */

#include <string>
#include <iostream>
#include <algorithm> 
using namespace std;
int main () {
    string str;
    getline (cin, str);
    if (str.length() < 5) {
        cout << "String length should be greater than 5." << endl;
        return 1;
    }
    reverse (str.begin() + 2, str.begin() + 6);
    cout << str << endl;
    return 0;
}