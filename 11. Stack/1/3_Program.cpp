// Push an element at any index/bottom
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

void pushAtIndex(std::stack <int>& st, int el, int idx) {
    std::stack<int> temp;

    while(st.size() > idx) {
        temp.push(st.top());
        st.pop();
    }
    st.push(el);

    while(!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main() {
    std::stack<int> s;
    s.push(1);
    s.push(2);  
    s.push(3);
    s.push(4);
    s.push(5);
    
    pushAtIndex(s, 10, 2);

    printStackElements(s);
    return 0;
}