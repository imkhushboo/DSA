/*
 Climb-Stairs : In how many distinct ways can you climb to the top?
  problem link : https://leetcode.com/problems/climbing-stairs/
*/

// Recursion

class Solution
{
public:
    int climbStairs(int n)
    {

        if (n <= 1)
            return 1;

        return climbStairs(n - 2) + climbStairs(n - 1);
    }
};

// DP

class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
