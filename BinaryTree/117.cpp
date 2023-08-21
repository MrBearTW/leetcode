// 117. Populating Next Right Pointers in Each Node II

// ref: 

/*
// Definition for a Node.
*/

#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        Node* dummy = new Node(0);

        while (head) {  // level
            Node* cur = dummy;  // cur is the last node of the next level
            while (head) {  // node
                if (head->left) {   // left child
                    cur->next = head->left;
                    cur = cur->next;
                }
                if (head->right) {  // right child
                    cur->next = head->right;
                    cur = cur->next;
                }
                head = head->next;  // next node
            }
            head = dummy->next; // next level
            dummy->next = NULL; // reset dummy
        }
        return root;
    }
};