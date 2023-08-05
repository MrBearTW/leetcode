// 270. Closest Binary Search Tree Value

// ref: https://leetcode.com/problems/closest-binary-search-tree-value/editorial/
// ref: https://leetcode.com/problems/closest-binary-search-tree-value/solutions/3474221/iterative-binary-search-solution-c/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int closestValue(TreeNode *root, double target)
    {
        int result = root->val;

        while (root != nullptr)
        {
            result = abs(root->val - target) < abs(result - target) ? root->val : result;   // update result if the current value is closer to target than previous result
            result = abs(root->val - target) == abs(result - target) ? min(root->val, result) : result; // if the current value is equidistant to target as the previous result, pick the smaller value between them as the result
            root = root->val > target ? root->left : root->right;   // go left or right depending on the value of the current node relative to target value
        }
        return result;
    }
};