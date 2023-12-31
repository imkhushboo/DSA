/*
find Shortest path in DAG
problem-link : https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
video - link : https://youtu.be/ZUFQfFaU-8U?si=FYEPkE7XP0plB-QZ


*/

<<<<<<< HEAD
class Solution
{
private:
    void topoSort(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &st)
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            int v = it.first;

            if (!vis[v])
            {
                topoSort(v, vis, adj, st);
            }
        }

        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // TOPO SORT

        int vis[N] = {0};
        stack<int> st;

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                topoSort(i, vis, adj, st);
            }
        }

        // step -2  omit all the stack element one by one and update the dist array

        vector<int> dist(N, 1e9);

        dist[0] = 0;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;

                if (dist[v] > (dist[node] + wt))
                {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dist[i] == 1e9)
                dist[i] = -1;
        }

        return dist;
    }
};

/*
=======
class Solution {
  private:
     void topoSort(int node,int vis[],vector<pair<int,int>>adj[],stack<int>&st)
     {
         vis[node] = 1;
         
         for(auto it : adj[node])
         {
             int v = it.first;
             
             if(!vis[v])
             {
                 topoSort(v,vis,adj,st);
             }
         }

         st.push(node);
     }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int,int>>adj[N];
         
         for(int i=0;i<M;i++)
         {
             int u = edges[i][0];
             int v = edges[i][1];
             int wt = edges[i][2];
             adj[u].push_back({v,wt});
         }
         
         
         // TOPO SORT
         
         int vis[N] = {0};
         stack<int>st;
         
         for(int i=0;i<N;i++)
         {
             if(!vis[i])
             {
                 topoSort(i,vis,adj,st);
             }
         }
         
         
         
         //step -2  omit all the stack element one by one and update the dist array
         
         vector<int>dist(N,1e9);
         
         dist[0] = 0;
         
         
         while(!st.empty())
         {
             int node = st.top();
             st.pop();
             
             
             for(auto it : adj[node])
             {
                 int v = it.first;
                 int wt = it.second;
                 
                 if(dist[v] > (dist[node] + wt))
                 {
                     dist[v] = dist[node] + wt;
                 }
             }
         }
         
         
         for(int i=0;i<N;i++)
         {
             if(dist[i] == 1e9) dist[i] = -1;
         }
        
        return dist;
         
    }
};



/* 
>>>>>>> fc3f9bbe7773e25f4b4a063db43c49f58c31b249
Time complexity :  O( N + M )
Space Complexity : O(N)

*/
<<<<<<< HEAD
=======


>>>>>>> fc3f9bbe7773e25f4b4a063db43c49f58c31b249
