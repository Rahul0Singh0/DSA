// Stack using linkedlist
// Array Stack: better memory efficiency and cache locality.
// Linked List Stack: flexible size and guaranteed O(1) push/pop.
#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* head;

public:
    Stack() : head(nullptr) {}

    // O(n)
    ~Stack() {
        while (!empty()) {
            pop();
        }
    }

    // O(1)
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // O(1)
    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    // O(1)
    T peek() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }

        return head->data;
    }

    // O(1)
    bool empty() const {
        return head == nullptr;
    }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    std::cout << "Top: " << s1.peek() << '\n';

    Stack<std::string> s2;
    s2.push("Hello");
    s2.push("World");

    std::cout << "Top: " << s2.peek() << '\n';
}