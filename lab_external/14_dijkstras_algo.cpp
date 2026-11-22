// 14. Implement Dijkstra’s algorithm to find the single source shortest path for a graph.

// Algorithm
// 1. Start.
// 2. Read the number of vertices and adjacency matrix.
// 3. Read the source vertex.
// 4. Initialize the distance of all vertices as infinity.
// 5. Set the source distance to zero.
// 6. Select the unvisited vertex with the smallest distance.
// 7. Update the distances of its adjacent vertices if a shorter path is found.
// 8. Mark the selected vertex as visited.
// 9. Repeat until all reachable vertices are processed.
// 10. Display the shortest distances.
// 11. Stop.

// T.C : O(V^2) ; S.C : O(V^2)

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

class Edge
{
public:
    int v, wt;
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstrasAlgo(int src, vector<vector<Edge>> g, int V)
{
    vector<int> dist(V, INT_MAX); // all vertices dist marked as infinity
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src}); // [dist[u], u]

    while (pq.size() > 0)
    {
        int u = pq.top().second;
        pq.pop();
        for (Edge e : g[u])
        {
            if (dist[e.v] > dist[u] + e.wt)
                dist[e.v] = dist[u] + e.wt;
            pq.push({dist[e.v], e.v});
        }
    }

    for (int i = 0; i < V; i++)
        cout << dist[i] << " ";
    cout << endl;
}

int main()
{
    int V = 6;

    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(2, 1));
    g[1].push_back(Edge(3, 7));

    g[2].push_back(Edge(4, 3));

    g[3].push_back(Edge(5, 1));

    g[4].push_back(Edge(3, 2));
    g[4].push_back(Edge(5, 5));

    cout << "\nShortest Paths from source : \n";
    dijkstrasAlgo(0, g, V);

    return 0;
}