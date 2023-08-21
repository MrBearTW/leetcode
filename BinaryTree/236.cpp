// 236. Lowest Common Ancestor of a Binary Tree

// ref: https://youtu.be/gs2LMfuOR9k

/**
 * Definition for a binary tree node.
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = root;

        // base case
        if (root == NULL)
        {
            return NULL;
        }

        // if p or q is the root, then the root is the LCA
        if (root == p || root == q)
        {
            return root;
        }

        // recursively find the LCA in the left subtree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);

        // recursively find the LCA in the right subtree
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // if p and q are in different subtrees, then the root is the LCA
        if (left != NULL && right != NULL)
        {
            return root;
        }

        // if p and q are in the same subtree, then the LCA is in that subtree
        if (left != NULL)
        {
            return left;
        }
        else
        {
            return right;
        }

        return ans;
    }
};