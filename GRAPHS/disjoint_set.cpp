/*
 Disjoint sets or Union by Rank
 problem -link : https://leetcode.com/problems/number-of-provinces/
 video link : https://youtu.be/aBxjDBC4M1U?si=X0qBVrpS1V_Ca6rz

*/

class DisjointSet
{
public:
    vector<int> rank;
    vector<int> parent;

    // path compression
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
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // Disjoint sets

        int n = isConnected.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionByRank(i + 1, j + 1);
                }
            }
        }
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            // cout<<ds.findPar(i)<<"\n";
            mp[ds.findPar(i)]++;
        }

        return mp.size();
    }
};

/*
  Time complexity - O(4X);

*/