/* print the lis
  problem - link : https://leetcode.com/problems/largest-divisible-subset/
  video - link : https://youtu.be/IFfYfonAFGc?si=JTOfJsiMmfBWJEMO
  Time complexity : O(N*N) + O(N);

*/

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 1), hash(n + 1);

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
        }

        int maxi = -1, ind = -1;

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev])
                {
                    if (dp[i] < (1 + dp[prev]))
                    {
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }

            if (maxi < dp[i])
            {
                maxi = dp[i];
                ind = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[ind]);

        while (hash[ind] != ind)
        {
            ind = hash[ind];
            ans.push_back(nums[ind]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
