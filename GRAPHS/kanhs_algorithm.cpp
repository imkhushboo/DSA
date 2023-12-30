/*
  Kanhs Algorithm : topological sorting using BFS
  problem -link : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
  video -link : https://youtu.be/73sneFXuTEg?si=vJQh9Yq_5839g7QO

*/

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // kanh's algorithm

        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {

            for (auto nodes : adj[i])
            {
                // cout<<nodes<<" ";
                indegree[nodes]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo;
    }
};

/*
 Time complexity :  O(V +  E)
 Space complexity:  O(N + N)
*/
