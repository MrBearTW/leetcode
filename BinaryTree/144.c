// 144. Binary Tree Preorder Traversal

// ref: https://leetcode.com/problems/binary-tree-preorder-traversal/solutions/1965692/c-100-iterative-recursive-o-n/?orderBy=most_votes&page=3&languageTags=c

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ans = malloc(100 * sizeof(int));
    struct TreeNode *stack[100] = {NULL};
    int idx = 0;
    
    *returnSize = 0;
    stack[idx++] = root;

    while (idx != 0)
    {
        struct TreeNode *node = stack[--idx];
        if (node != NULL)
        {
            ans[(*returnSize)++] = node->val;
            stack[idx++] = node->right;
            stack[idx++] = node->left;
        }
    }
    return ans;
}

