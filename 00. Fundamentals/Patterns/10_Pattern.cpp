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
        for(int j = 1;  j <= n; j++) {
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

/*
   1
  121
 12321
1234321
*/

void pattern2(int n) {
    for(int i = 1; i <= n; i++) {
        int j;
        for(j = 1; j <= n-i; j++) {
            std::cout<<" ";
        }
        for(j = 1; j <= i; j++) {
            std::cout<<j;
        }
        for(int k = j-2; k >= 1; k--) {
            std::cout<<k;
        }
        std::cout<<std::endl;
    }
}

/*
   *
  ***
 *****
*******
 *****
  ***
   *
*/

void pattern3(int n) {
    int a = 1;
    int b = n-1;
    for(int i = 1; i <= n*2-1; i++) {
        for(int j = 1; j <= b; j++) {
            std::cout<<" ";
        }
        if(i <= n-1) b--;
        else b++;
        for(int j = 1; j <= a; j++) {
            std::cout<<"*";
        }
        if(i <= n-1) a += 2;
        else a -= 2;
        std::cout<<std::endl;
    }
}

int main() {
    int n;
    std::cin>>n;
    pattern3(n);
    return 0;
}