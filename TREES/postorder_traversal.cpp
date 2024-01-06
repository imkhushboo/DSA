
/*
  Post Order Traversal
  problem - link : https://leetcode.com/problems/binary-tree-postorder-traversal/
  video - link : https://youtu.be/NzIGLLwZBS8?si=TFH8XpJ0ejzhGmso

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
    void postorder(TreeNode *root, vector<int> &vp)
    {
        if (root == NULL)
            return;
        postorder(root->left, vp);
        postorder(root->right, vp);
        vp.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        // left right root
        vector<int> vp;
        postorder(root, vp);
        return vp;
    }
};

// iterative using single stack
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        // left right root
        stack<TreeNode *> st;
        vector<int> ans;
        if (root == NULL)
            return {};
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            ans.push_back(node->val);
            st.pop();

            if (node->left)
            {
                st.push(node->left);
            }

            if (node->right)
            {
                st.push(node->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};