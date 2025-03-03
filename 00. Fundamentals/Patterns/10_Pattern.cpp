#include <iostream>

/*
   ****
  ****
 ****
****
*/

void pattern(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            std::cout<<" ";
        }
        for(int j = 1; j <= n; j++) {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

/*
   *
  ***
 *****
*******
*/

void pattern1(int n) {
    int a = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n-i; j++) {
            std::cout<<" ";
        }
        for(int j = 1; j <= a; j++) {
            std::cout<<"*";
        }
        a += 2;
        std::cout<<std::endl;
    }
}

int main() {
    int n;
    std::cin>>n;
    pattern1(n);
    return 0;
}