/*
You have two stack and 1,2,3,4,5 values and you have pushed all these values to S1 (in the order
1,2,3,4,5) and then you took 2 elements from top and inserted into S2 , then pop 1 element from S1
and then take top of S2 and insert into S1. What is the second top element in S1. 
*/
#include <iostream>
#include <stack>

int main() {
    std::stack <int> s1, s2;
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.push(2);
    s1.push(1);
    
    s2.push(s1.top());
    s1.pop();
    s2.push(s1.top());

    s1.push(s2.top());

    s1.pop();
    std::cout << s1.top();
    return 0;
}