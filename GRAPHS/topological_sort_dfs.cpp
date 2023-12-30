/*
 Toplogical sort  using DFS
  definition :  it is linear ordering of vertices such that if there is an edge
                between u and v , u appears before v in their ordering .
   Note: ordering can only be done in DAG (directed Acyclic Graph)

   problem link : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
   video link : https://youtu.be/5lZ0iJMrUMk?si=8ilcYj8Q4Y1l7WYR
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, st, adj);
            }
        }

        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, st, adj);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends

/* Time complexity :  O(V + E)
   Space complexity : O(2*N)
  */