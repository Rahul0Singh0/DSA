// Stack implementation using array
#include <iostream> 
#include <vector>

template <typename T>

struct Stack {
    private:
        T* arr;
        int capacity;
        int topIndex;

    public:
        Stack(int size = 10) : capacity(size), topIndex(-1) {
            arr = new T[capacity];
        }

        ~Stack() {
            delete[] arr;
        }

        void push(T a) {
            if (topIndex == capacity - 1) {
                throw std::overflow_error("Stack overflow");
            }
            arr[++topIndex] = a;
        }

        void pop() {
            if(empty()) {
                throw std::underflow_error("Stack underflow");
            }
            arr[--topIndex];
        }

        T top() const {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            return arr[topIndex];
        }

        bool empty() const {
            return topIndex == -1;
        }
};

int main() {
    Stack<int> st;

    st.push(1);
    st.push(2);

    std::cout << st.top() << std::endl;
    std::cout << st.empty() << std::endl;
    st.pop();
    st.pop();
    std::cout << st.empty() << std::endl;
    st.pop();

    return 0;
}