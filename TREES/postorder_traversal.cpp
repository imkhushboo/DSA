
/*
  Post Order Traversal
  problem - link : https://leetcode.com/problems/binary-tree-postorder-traversal/

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