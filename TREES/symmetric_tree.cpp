
/*
   check symmetric tree
   problem - link : https://leetcode.com/problems/symmetric-tree/
*/

// iterative
class Solution
{

public:
    bool isSymmetric(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<TreeNode *> temp;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                temp.push_back(node);
                q.pop();
            }

            for (int i = 0; i < n; i++)
            {
                if (temp[i] == NULL and temp[n - i - 1] == NULL)
                {
                    continue;
                }
                else if (temp[i] == NULL)
                    return false;
                else if (temp[n - i - 1] == NULL)
                    return false;
                else if (temp[i]->val != temp[n - i - 1]->val)
                {
                    return false;
                }
                q.push(temp[i]->left);
                q.push(temp[i]->right);
            }
        }

        return true;
    }
};