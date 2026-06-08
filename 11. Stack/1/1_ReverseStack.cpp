#include <iostream> 
#include <stack>
#include <vector>

void printStackElements (std::stack<int> st) {
    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);  
    s.push(3);
    s.push(4);
    s.push(5);
    printStackElements(s);
    std::stack<int> reversedStack; // using an auxiliary stack
    
    std::vector<int> reversedElements; // using a vector/array reversed stack
    while (!s.empty()) {
        reversedStack.push(s.top());
        reversedElements.push_back(s.top());
        s.pop();
    }

    printStackElements(reversedStack);

    for (int el : reversedElements) {
        s.push(el);
    }

    printStackElements(s); 
    
    return 0;
}