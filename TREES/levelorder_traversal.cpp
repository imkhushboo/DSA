/*
  Level order traversal
  problem - link : https://leetcode.com/problems/binary-tree-level-order-traversal/


*/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                temp.push_back(node->val);
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
            ans.push_back(temp);
        }

        return ans;
    }
};