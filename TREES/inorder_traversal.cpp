/*
  Inorder Traversal of Binary Tree
  problem - link : https://leetcode.com/problems/binary-tree-inorder-traversal
  video - link : https://youtu.be/lxTGsVXjwvM?si=orUHMf2Lh2BvdJw4
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
class Solution
{
public:
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // left root right
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};

// iterative traversal

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        // iterative traversal

        stack<TreeNode *> st;
        st.push(root);
        vector<int> ans;

        while (!st.empty())
        {
            TreeNode *node = st.top();

            if (node == NULL)
            {
                st.pop();
                if (!st.empty())
                {
                    TreeNode *node = st.top();
                    ans.push_back(node->val);
                    st.pop();
                    st.push(node->right);
                }
                else
                {
                    break;
                }
            }
            else
            {
                st.push(node->left);
            }
        }

        return ans;
    }
};