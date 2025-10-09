#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src)
{
    // V = number of vertices
    // adj[u] = vector of {v, weight} pairs

    vector<int> dist(V, INT_MAX); // Distance array
    dist[src] = 0;

    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();

        // If this distance is not optimal anymore, skip
        if (d > dist[node])
            continue;

        // Explore neighbors
        for (auto [adjNode, wt] : adj[node])
        {
            if (dist[node] + wt < dist[adjNode])
            {
                dist[adjNode] = dist[node] + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Example graph (undirected)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 4});
    adj[2].push_back({1, 4});

    adj[0].push_back({3, 1});
    adj[3].push_back({0, 1});

    adj[3].push_back({2, 3});
    adj[2].push_back({3, 3});

    adj[2].push_back({4, 5});
    adj[4].push_back({2, 5});

    int src = 0;
    vector<int> dist = dijkstra(V, adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
