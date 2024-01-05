/*
 Preorder Traversal of Binary Tree
 problem - link : https://leetcode.com/problems/binary-tree-preorder-traversal

*/

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

// recursive traversal

class Solution
{
private:
    void preorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        ans.push_back(root->val);

        preorder(root->left, ans);
        preorder(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // root left right

        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};

// iterative traversal

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        // iterative preorder traversal

        if (root == NULL)
            return {};

        stack<TreeNode *> st;
        vector<int> ans;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *node = st.top();
            ans.push_back(node->val);
            st.pop();
            if (node->right)
            {
                st.push(node->right);
            }

            if (node->left)
            {
                st.push(node->left);
            }
        }
        return ans;
    }
};