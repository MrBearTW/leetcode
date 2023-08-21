// 145. Binary Tree Postorder Traversal

// ref: https://leetcode.com/problems/binary-tree-postorder-traversal/solutions/1965782/c-100-iterative-solution-o-n/?orderBy=most_votes&page=3&languageTags=c

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

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode *stack[100] = {NULL};
    int idx = 0, i, j, temp;

    while (idx || root)
    {
        if (root)
        {
            stack[idx++] = root;
            ans[(*returnSize)++] = root->val;
            root = root->right;
        }
        else
        {
            struct TreeNode *node = stack[--idx];
            root = node->left;
        }
    }

    j = *returnSize - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = ans[j];
        ans[j] = ans[i];
        ans[i] = temp;
    }
    return ans;
}