/*
  Diameter of a Binary Tree
  problem - link : https://leetcode.com/problems/diameter-of-binary-tree/


*/

class Solution
{
public:
    int ans = 0;
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = helper(root->left);
        int right = helper(root->right);

        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        helper(root);
        return ans;
    }
};