/**
 *   *
 *   *
 * *****
 *   *
 *   *
 */
/**
 *  *
 * ***
 *  *
 */
/**
 *    *
 *    *
 *    *
 * *******
 *    *
 *    *
 *    *
 */
#include <iostream>
void pattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == n/2+1 || j == n/2+1) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    int n;
    std::cin>>n;
    pattern(n);
    return 0;
}