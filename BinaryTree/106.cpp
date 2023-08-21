// 106. Construct Binary Tree from Inorder and Postorder Traversal

// ref: https://youtu.be/vm63HuIU7kw
// ref: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solutions/3302159/easy-solutions-in-java-python-and-c-look-at-once/

/**
 * Definition for a binary tree node.

 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int postStart = 0;
        int postEnd = postorder.size() - 1;

        return buildTree(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootVal = postorder[postEnd];
        int rootIndex = 0;
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }

        int len = rootIndex - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + len - 1);
        root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + len, postEnd - 1);

        return root;
    }
}; 