// Copying elements from stack into another in same order
#include <iostream> 
#include <stack>
#include <vector>

void printStackElements(std::stack<int> st) {
    while(!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;
}

void copyingStackElements(std::stack<int>& st, std::stack<int>& dest) {
    if (st.empty()) {
        return;
    }

    int top = st.top();
    st.pop();

    copyingStackElements(st, dest);

    dest.push(top);
    st.push(top);
}

// These all three having same complexity: space O(N) and time O(N)
int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);  
    s.push(3);
    s.push(4);
    s.push(5);
    
    // first method
    // std::stack<int> temp = s;
    
    // printStackElements(s);
    // printStackElements(temp);

    // Second method - using helper stack
    // std::stack <int> helper;
    std::stack <int> dest;

    // while (!s.empty()) {
    //     helper.push(s.top());
    //     s.pop();
    // }
    // while (!helper.empty()) {
    //     dest.push(helper.top());
    //     helper.pop();
    // }
    // printStackElements(dest);

    // Third method - recursion
    copyingStackElements(s, dest);

    printStackElements(dest);

    return 0;
}