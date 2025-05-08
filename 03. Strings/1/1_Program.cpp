/**
 * Input a string of length n & count all the vowels in it.
 */

#include <iostream>
#include <unordered_set>
using namespace std;
int main () {
    string str;
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    cout << "Enter a string: ";
    getline(cin, str); // Use getline to read the entire line including 
    
    int count = 0;

    for (char c : str) {
        if (vowels.find(c) != vowels.end()) {
            count++;
        }
    }

    cout << "Number of vowels in the string: " << count << endl;
    
    return 0;
}