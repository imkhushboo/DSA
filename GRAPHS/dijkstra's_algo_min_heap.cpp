/*
 find shortest path using DIJKSTRA'S ALGORITHM with min - heap data structure
 problem-link :  https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
 video-link: https://youtu.be/V6H1qAeB-l4?si=ge5Vx5xLW0ADMY4Q


*/

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // priority queue

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(V, 1e9);
        dist[S] = 0;

        pq.push({0, S});

        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto it : adj[node])
            {

                int wt = it[1];
                int v = it[0];

                if (dis + wt < dist[v])
                {
                    dist[v] = dis + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

/*
Time complexity : O(E*log(V))
Space complexity : O(E)
*/
