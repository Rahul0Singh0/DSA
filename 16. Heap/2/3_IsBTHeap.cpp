// Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1\
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    // int sizeOfTree(struct Node* tree) {
    //     if(tree == nullptr) return 0;
    //     else return 1+sizeOfTree(tree->left)+sizeOfTree(tree->right);
    // }
    // level order technique
    bool isCBT(struct Node* tree) {
        // int size = sizeOfTree(tree);
        queue<struct Node*> q;
        // int count = 0;
        q.push(tree);
        bool nullFound = false;
        while(!q.empty()) {
            struct Node* temp = q.front();
            q.pop();
            if(temp == nullptr) nullFound = true;
            else if(temp != nullptr) {
                if(nullFound) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        // if(q.size() > 0) {
        //     Node* temp = q.front();
        //     if(temp != nullptr) return false;
        //     q.pop();
        // }
        return true;
    }
    bool isMax(struct Node* root) {
        if(!root->left && !root->right)
          return true;
        if(!root->right)
          return (root->data > root->left->data);
        // else if(root->left)
        //   return (root->data > root->left->data);
        else
        {  
            bool left = isMax(root->left);
            bool right = isMax(root->right);
            
            return (left && right && root->data > root->right->data &&
           root->data > root->left->data);
            
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        return isCBT(tree) && isMax(tree);
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends