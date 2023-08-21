// 102. Binary Tree Level Order Traversal

// ref: https://leetcode.com/problems/binary-tree-level-order-traversal/solutions/1602435/c-iterative-solution-using-a-queue/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    if (!root)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode *q[1001];
    int head = 0;
    int tail = 0;
    int **ans = malloc(sizeof(*ans) * 2000);
    *returnColumnSizes = malloc(sizeof(**returnColumnSizes) * 2000);

    q[tail++] = root;

    while ((tail - head) % 1001)
    {
        int sz = (*returnColumnSizes)[*returnSize] = (tail - head) % 1001;
        ans[*returnSize] = malloc(sizeof(**ans) * sz);

        for (int i = 0; i < sz; i++)
        {
            struct TreeNode *p = q[head++ % 1001];
            ans[*returnSize][i] = p->val;

            if (p->left)
            {
                q[tail++ % 1001] = p->left;
            }
            if (p->right)
            {
                q[tail++ % 1001] = p->right;
            }
        }
        (*returnSize)++;
    }
    return ans;
}