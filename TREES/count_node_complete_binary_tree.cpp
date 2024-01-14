
/*

Count no of nodes in Complete Binary Tree
  problem - link :https://leetcode.com/problems/count-complete-tree-nodes/
*/

class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        queue<TreeNode *> q;
        q.push(root);

        int ans = 0;
        while (!q.empty())
        {
            TreeNode *node = q.front();

            ans++;
            q.pop();

            if (node->left)
            {
                q.push(node->left);
            }

            if (node->right)
            {
                q.push(node->right);
            }
        }

        return ans;
    }
};