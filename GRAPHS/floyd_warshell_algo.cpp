/*
  floyd warshell algorithm for negative path weight or cycle
 shortest path algorithm from every node to every another node

 problem - link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
 video - link : https://youtu.be/YbY8cVwWAvw?si=BXjMiMwaU4mJKVLK

*/

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 1e9;
                }
                if (i == j)
                    matrix[i][j] = 0;
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        // check if negative cycle exists or not

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0)
                {
                    // negative cycle exists
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 1e9)
                {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};
/*
  Time complexity : O(N^3)
  Space Complexity: O(N^2)

*/