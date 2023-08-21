// 94. Binary Tree Inorder Traversal

// ref: https://leetcode.com/problems/binary-tree-inorder-traversal/solutions/1287690/c-solution-100-faster-iterative-and-recursive-version/?orderBy=most_votes&languageTags=c

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

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int *ans = malloc(100 * sizeof(int));
    struct TreeNode **stack = malloc(100 * sizeof(struct TreeNode *));
    int top = 0;
    *returnSize = 0;
    while (top || root)
    {
        if (root)
        {
            stack[top++] = root;
            root = root->left;
        }
        else
        {
            root = stack[--top];
            ans[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    free(stack);
    ans = realloc(ans, (*returnSize) * sizeof(int));
    return ans;
}

View Unofficial Transcript
Intent to Enroll
Request Official Transcript
Honours and Awards
Advising Comments
View Transfer Credit Report
Enrollment Verification
View What-if Report
View Graduation Status
Convocation RSVP
Transfer Credit Request
View ReportView All Requested Reports
New Request
Submit
Report Type

Advising Transcript
