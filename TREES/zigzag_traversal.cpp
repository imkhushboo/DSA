

/*
 Zig Zag traversal or Spiral traversal of binary tree
 problem -link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 video  -link : https://youtu.be/3OXWEdlIGl4?si=yz5W5ehrC2Yb0buq

*/

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;
        int cnt = 0;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();

                q.pop();

                temp.push_back(node->val);

                if (node->left)
                {
                    q.push(node->left);
                }

                if (node->right)
                {
                    q.push(node->right);
                }
            }

            if (cnt % 2)
            {
                reverse(temp.begin(), temp.end());
            }
            cnt++;
            ans.push_back(temp);
        }

        return ans;
    }
};