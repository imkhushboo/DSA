/*
  Amount of Time for Binary Tree to Be Burnt
  problem - link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
  video - link : https://youtu.be/2r5wLmQfD6g?si=jUyxIARwQnD9QR7Z

*/

class Solution
{
public:
    int timeToBurnTarget(TreeNode *target, map<TreeNode *, TreeNode *> &mp)
    {

        queue<TreeNode *> q;
        q.push(target);
        map<TreeNode *, int> vis;
        vis[target] = 1;
        int time = 0;
        while (!q.empty())
        {
            int n = q.size();
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();

                q.pop();

                // left

                if (node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = 1;
                    flag = 1;
                }

                // right

                if (node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = 1;
                    flag = 1;
                }

                // parents

                if (mp[node] && !vis[mp[node]])
                {
                    q.push(mp[node]);
                    vis[mp[node]] = 1;
                    flag = 1;
                }
            }

            if (flag == 1)
            {
                time++;
            }
        }

        return time;
    }

    TreeNode *mapParents(TreeNode *root, map<TreeNode *, TreeNode *> &mp, int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->val == start)
            {
                res = node;
            }

            // left
            if (node->left)
            {
                mp[node->left] = node;
                q.push(node->left);
            }

            // right

            if (node->right)
            {
                mp[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        map<TreeNode *, TreeNode *> mp;
        TreeNode *target = mapParents(root, mp, start);
        return timeToBurnTarget(target, mp);
    }
};