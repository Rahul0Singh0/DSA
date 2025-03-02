/*

1
2 3
4 5 6
7 8 9 10

*/

#include <iostream>

void pattern(int n) {
    int a = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            std::cout<<a++<<" ";
        }
        std::cout<<std::endl;
    }
}

/*

1
01
101
0101
10101

*/

void pattern1(int n) {
    bool flag = 1;
    for(int i = 1; i <= n; i++) {
        flag = (i % 2) ? true : false;
        for(int j = 1; j <= i; j++) {
            std::cout<<flag<<" ";
            flag = !flag;
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