/*
Remove kth element from top in a given stack.
*/

#include <iostream>
#include <stack>
int main () {
    std::stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);

    int n; // Kth elements
    std::cin >> n;
    int i = 0;
    while (i < n) {
        s.pop();
        i++;
    }

    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }

    return 0;
}