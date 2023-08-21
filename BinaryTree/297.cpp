// 297. Serialize and Deserialize Binary Tree

// ref: https://youtu.be/u4JAi2JJhI8

/**
 * Definition for a binary tree node.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Use DFS to serialize and deserialize
class Codec
{
public:
    void dfs_serialize(TreeNode *root, string &s)
    {
        // base case
        if (root == NULL)
        {
            s += "null,";
            return;
        }
        // preorder traversal (root, left, right) to serialize the tree into a string
        s += to_string(root->val) + ",";
        dfs_serialize(root->left, s);
        dfs_serialize(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s = "";
        dfs_serialize(root, s);
        return s;
    }

    TreeNode *dfs_deserialize(vector<string> &data, int &i)
    {
        // base case
        if (data[i] == "null")
        {
            return NULL;
        }
        // preorder traversal (root, left, right) to deserialize the string into a tree
        TreeNode *root = new TreeNode(stoi(data[i])); // stoi: convert string to int
        i++;
        root->left = dfs_deserialize(data, i); // i is passed by reference, so it will be updated
        i++;
        root->right = dfs_deserialize(data, i); // i is passed by reference, so it will be updated
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> tree;
        string s = "";
        // split the string into a vector of strings
        for (char c : data)
        {
            if (c == ',') // ',' is the delimiter
            {
                tree.push_back(s);
                s = "";
            }
            else // if c != ',' then add c to s to form a string of a number
            {
                s += c;
            }
        }
        int i = 0;
        return dfs_deserialize(tree, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));