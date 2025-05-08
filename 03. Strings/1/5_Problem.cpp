/**
 * Return the total number of digits in a number without using any loop.
 */
#include <iostream>
#include <string>
using namespace std;
int countDigits(int n) {
    if (n == 0) return 1; // Base case
    return (n < 10) ? 1 : 1 + countDigits(n / 10); // Recursive case
}
int main () {
    int num;
    cin >> num;
    string str = to_string(num); 
    cout << "Total number of digits: " << str.size() << endl;
    return 0;
}