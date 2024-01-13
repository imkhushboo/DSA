/*
Lowest Common Ancestor of Binary tree
  problem - link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if ((left == p || right == p) and (left == q || right == q))
        {
            return root;
        }
        else if ((root == p || root == q) and ((left == p || right == p) and
                                               (left == q || right == q)))
        {
            return root;
        }
        else if (left == NULL and right != NULL)
        {
            return right;
        }
        else if (right == NULL and left != NULL)
        {
            return left;
        }

        return NULL;
    }
};