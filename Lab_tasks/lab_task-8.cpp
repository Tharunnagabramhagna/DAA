/* Q) Write a program to implement Floyd Warshall Algorithm to find the shortest path between every pair of the vertices. */

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
public:
    vector<vector<pair<int, int>>> adj;
    int V;

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt)
    {
        adj[u].push_back({v, wt});
    }

    void floydWarshall()
    {
        const int INF = 1e9;

        vector<vector<int>> dist(V, vector<int>(V, INF));

        // Mark the self distances as zero (e.g. 0 --> 0 => 0)
        for (int i = 0; i < V; i++)
            dist[i][i] = 0;

        // Intialize the values of each vertex
        for (int u = 0; u < V; u++)
        {
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = wt;
            }
        }

        // Iterate the values V times
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        // Print the final min values
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph(4);

    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 11);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 8);
    graph.addEdge(2, 3, 3);

    graph.floydWarshall();
}