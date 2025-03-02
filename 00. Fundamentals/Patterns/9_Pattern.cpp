/*

   *
  **
 ***
****

*/

#include <iostream>

void pattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            std::cout<<" ";
        }
        for(int j = 1; j <= i; j++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

/*
   1
  12
 123
1234
*/

void pattern1(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            std::cout<<" ";
        }
        for(int j = 1; j <= i; j++) {
            std::cout<<j;
        }
        std::cout<<std::endl;
    }
}

int main() {
    int n;
    std::cin>>n;
    pattern1(n);
    return 0;
}