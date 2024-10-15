#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // Default Constructor
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    void display(ListNode *node) {
        while(node != nullptr) {
            cout<<node->val<<" ";
            node = node->next;
        }
    }
};

int main() {
    int n; // no. of node
    cin>>n;
    ListNode *node = new ListNode(0);
    ListNode *t = node; 
    while(n--) {
        int val; cin>>val;
        ListNode *temp = new ListNode(val);
        t->next = temp;
        t = t->next;
    }
    node = node->next;
    LinkedList ll;
    ll.display(node);
    return 0;
}