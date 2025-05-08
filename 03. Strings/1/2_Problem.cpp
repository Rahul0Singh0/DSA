/**
 * Input a string of size n & update all the even positions in the string to character 'a'.
 */
/**
 * Note : In C/C++, string is mutable, so we can change the characters in the string.
 */
 #include <iostream>
 using namespace std;
 int main () {
    string str;
    getline(cin, str);
    cout << "Original string: " << str << endl;
    for (int i = 0; i < str.size(); i++) {
        if (i % 2 == 0) {
            str[i] = 'a';
        }
    }
    cout << "Updated string: " << str << endl;
    return 0;
 }