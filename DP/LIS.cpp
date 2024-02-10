/* find the length of LIS

problem link : https://leetcode.com/problems/longest-increasing-subsequence/
video link : https://youtu.be/ekcwMsSIzVc?si=rQ_M6t-GCxzr_jWh

*/

// -------------------- recursion ----------------------------
/* Time complexity : O(2^N) */

class Solution
{
public:
    // recursion

    int helper(int curr, int prev, vector<int> &nums)
    {
        int n = nums.size();
        if (curr == n)
        {
            return 0;
        }

        // not take
        int ans = helper(curr + 1, prev, nums);

        // take

        if (prev == -1 or nums[curr] > nums[prev])
        {
            ans = max(ans, 1 + helper(curr + 1, curr, nums));
        }

        return ans;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return helper(0, -1, nums);
    }
};

// -----------------Memoization------------------------------------------
/* Time complexity : O(N*N) */

class Solution
{
public:
    // memoization

    int dp[2501][2501];

    int helper(int curr, int prev, vector<int> &nums)
    {
        int n = nums.size();
        if (curr == n)
        {
            return 0;
        }

        if (dp[curr][prev + 1] != -1)
        {
            return dp[curr][prev + 1];
        }

        // not take
        int ans = helper(curr + 1, prev, nums);

        // take

        if (prev == -1 or nums[curr] > nums[prev])
        {
            ans = max(ans, 1 + helper(curr + 1, curr, nums));
        }

        return dp[curr][prev + 1] = ans;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return helper(0, -1, nums);
    }
};

// ------------------ Tabulation -----------------------------------
/*  Time complexity : O(N*N)
    Space complexity : O(N)
 */

class Solution
{
public:
    // tabulation 1.

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // not take
                int ans = dp[curr + 1][prev + 1];

                // take

                if (prev == -1 or nums[curr] > nums[prev])
                {
                    ans = max(ans, 1 + dp[curr + 1][curr + 1]);
                }
                dp[curr][prev + 1] = ans;
            }
        }

        return dp[0][0];
    }

    // tabulation 2
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0), now(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                // not take
                int ans = next[prev + 1];

                // take

                if (prev == -1 or nums[curr] > nums[prev])
                {
                    ans = max(ans, 1 + next[curr + 1]);
                }
                now[prev + 1] = ans;
            }
            next = now;
        }

        return next[0];
    }
};

// ------------------ Algorithm ------------------
/*   time complexity : O(N*N) , space-complexity : O(N)*/

class Solution
{
public:
    // Algorithm

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[i] > nums[prev])
                {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
        }

        int ans = 1;

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

// ------------------ Binary Search ------------------------

class Solution
{
public:
    // Binary Search O(N*log(N))

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > temp.back())
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind =
                    lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        //         for(auto x: temp)
        //         {
        //             cout<<x<<" ";
        //         }

        return temp.size();
    }
};
