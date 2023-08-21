// 116. Populating Next Right Pointers in Each Node

// ref: https://youtu.be/U4hFQCa1Cq0

/*
// Definition for a Node.
*/

#include <iostream>
#include <vector>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;

        Node *leftNode = root->left;
        Node *rightNode = root->right;

        while (leftNode != NULL)
        {
            leftNode->next = rightNode;  // connect left to right
            leftNode = leftNode->right;  // move left to right
            rightNode = rightNode->left; // move right to left
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};