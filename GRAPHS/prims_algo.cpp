/*
  Prims Algorithm to find MST (Minimum Spanning Tree)
  problem - link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
  video -link : https://youtu.be/mJcZjjKzeqk?si=cgHEAe5FUqd_Obfy

*/
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // prim's algo
        vector<int> vis(V, 0);
        // {wt,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (vis[node] == 1)
                continue;

            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int v = it[0];
                int edgewt = it[1];

                if (!vis[v])
                {
                    pq.push({edgewt, v});
                }
            }
        }

        return sum;
    }
};
/*

  Time complexity : O( Elog(E))
  Space complexity : O(E);


*/
