
/*
  vertical order traversal of binary tree
  problem -link : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

*/

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});

        map<int, vector<pair<int, int>>> mp;

        while (!q.empty())
        {
            TreeNode *node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            mp[y].push_back({x, node->val});

            if (node->left)
            {
                q.push({node->left, {x + 1, y - 1}});
            }

            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto x : mp)
        {
            vector<pair<int, int>> temp = x.second;
            sort(temp.begin(), temp.end());
            vector<int> ntemp;

            for (auto x : temp)
            {
                ntemp.push_back(x.second);
            }
            ans.push_back(ntemp);
        }

        return ans;
    }
};