
/* Detect a cycle in undirected graph using BFS
question link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
video link - https://youtu.be/BPlrALf1LDU?si=rTOaUC3I-2rOppOi

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool detectCycle(int src, int vis[], vector<int> adj[])
    {

        queue<pair<int, int>> q;
        q.push({src, -1});
        vis[src] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;

            q.pop();

            for (auto &it : adj[node])
            {
                // cout<<it<<" ";
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent)
                {
                    return true;
                }
            }
        }

        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])

            {
                if (detectCycle(i, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

/*
    N - no. of Nodes in graph
    E - edges in the graph

    Time complexity -
    1. NOT CONNECTED COMPONENT:  O(N + 2E)
    2. CONNECTED COMPONENT  : O(N + 2E) + O(N)

    Space complexity -    O(N) + O(N) ~ O(N)


*/
