/*Detect cyle in directed graph using DFS
 problem link  : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
 video link : https://youtu.be/9twcmtQj4DU?si=eO9a4mJ5TvFMFxHU


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    bool dfs(int node, vector<int> adj[], vector<int> &pathVis, vector<int> &vis)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, adj, pathVis, vis) == true)
                    return true;
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, pathVis, vis) == true)
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

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends

/* Time Complexity : O(V+ E)
   Space Complexoty : O(2*N)
*/