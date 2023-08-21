// 250. Count Univalue Subtrees

// ref: https://leetcode.com/problems/count-univalue-subtrees/editorial/

/**
 * Definition for a binary tree node.

 */

#include <iostream>
#include <vector>


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
    int count = 0;

    bool isUnival(TreeNode *root, int val)
    {
        if (root == nullptr)
            return true;
        if (root->val != val)
            return false;
        return isUnival(root->left, val) && isUnival(root->right, val);
    }

    int countUnivalSubtrees(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (isUnival(root, root->val))
            count++;
        countUnivalSubtrees(root->left);
        countUnivalSubtrees(root->right);
        return count;
    }
};