/*
  Bellmen Fords Algorithm for negative path weight
  problem - link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
  video - link : https://youtu.be/0vVofAhAYjc?si=5LPgj_hmyxan-Xio

*/

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V, 1e8);
        dist[S] = 0;

        // Relaxation

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                if (dist[u] != 1e8 and dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Nth iteration check if it is negative cycle or not
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 and dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};

/*
 Time complexity : O(V * E);
 Space Complexity : O(V);
*/