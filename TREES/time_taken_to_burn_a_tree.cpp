/*
minimum time to burn a tree from a node
 problem -link : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 video - link : https://youtu.be/2r5wLmQfD6g?si=YLRlxFuYKnpycBfJ


*/

class Solution
{
public:
    int findtime(TreeNode *target, map<TreeNode *, TreeNode *> &mp)
    {
        queue<TreeNode *> q;
        int time = 0;
        map<TreeNode *, int> vis;
        vis[target] = 1;

        q.push(target);

        while (!q.empty())
        {
            int n = q.size();
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();

                q.pop();

                if (node->left and !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = 1;
                    flag = true;
                }

                if (node->right and !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = 1;
                    flag = true;
                }

                if (mp[node] and !vis[mp[node]])
                {
                    q.push(mp[node]);
                    vis[mp[node]] = 1;
                    flag = true;
                }
            }

            if (flag)
            {
                time++;
            }
        }

        return time;
    }

    TreeNode *findParent(TreeNode *root, map<TreeNode *, TreeNode *> &mpp, int start)
    {

        queue<TreeNode *> q;
        q.push(root);

        TreeNode *res = NULL;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            if (node->val == start)
            {
                res = node;
            }
            q.pop();

            if (node->left)
            {
                mpp[node->left] = node;
                q.push(node->left);
            }

            if (node->right)
            {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int amountOfTime(TreeNode *root, int start)
    {
        // similar as minimum time to burn a tree from a node

        map<TreeNode *, TreeNode *> mpp;
        TreeNode *node = findParent(root, mpp, start);
        return findtime(node, mpp);
    }
};

/*
  Time complexity : O(N) + O(N) ~ O(N)
  space complexity : O(N)


*/