/*
  Krushkal Algorithm to find MST
  problem link : https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
  video-link : https://youtu.be/DMnDM_sxVig?si=e7dDXdjjgFfv-L_G
*/

class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;

    int findPar(int u)
    {
        if (u == parent[u])
        {
            return u;
        }

        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        DisjointSet ds(V);

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int u = it[0];
                int wt = it[1];

                edges.push_back({wt, {i, u}});
            }
        }

        sort(edges.begin(), edges.end());
        int sum = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v))
            {
                sum += wt;
                ds.unionByRank(u, v);
            }
        }

        return sum;
    }
};

/*
  Time complexity : O(Elog(E))+ O(4 alpha)
  Space complexity : O(E)
*/
