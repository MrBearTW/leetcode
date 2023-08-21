// 112. Path Sum

// ref: https://youtu.be/LSKQyOz_P8I

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // No root
        if (root == nullptr) {
            return false;
        }

        // Only root
        if (root->left == nullptr && root->right == nullptr) {
            return (root->val == targetSum);
        }

        // Recursion
        int newTargetSum = targetSum - root->val;
        bool left = hasPathSum(root->left, newTargetSum);
        bool right = hasPathSum(root->right, newTargetSum);
        return (left || right);
    }
};