
/*
  Right /left view of Binary Tree

  problem - link : https://leetcode.com/problems/binary-tree-right-side-view/


*/

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> temp;

        while (!q.empty())
        {

            int n = q.size();
            TreeNode *last = NULL;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                last = node;
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

            temp.push_back(last->val);
        }

        return temp;
    }
};