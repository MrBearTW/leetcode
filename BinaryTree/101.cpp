// 101. Symmetric Tree

// ref: https://youtu.be/Mao9uzxwvmc

/**
 * Definition for a binary tree node.
 */

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
    // Use dfs to check if the tree is symmetric
    bool isSymmetric(TreeNode *root)
    {
        // No root
        if (root == nullptr)
        {
            return true;
        }

        // Only root
        if (root->left == nullptr && root->right == nullptr)
        {
            return true;
        }

        // Recursion
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *left, TreeNode *right)
    {
        // Both are nullptr
        if (left == nullptr && right == nullptr)
        {
            return true;
        }

        // One of them is nullptr
        if (left == nullptr || right == nullptr)
        {
            return false;
        }

        // Both are not nullptr
        if (left->val != right->val)
        {
            return false;
        }

        // Recursion
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};