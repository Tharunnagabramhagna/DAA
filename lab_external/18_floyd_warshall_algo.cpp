// 18. Implement Floyd Warshall algorithm to find All-to-all shortest paths.

// Algorithm 
// 1. Start.
// 2. Read the number of vertices and adjacency matrix.
// 3. Initialize the distance matrix using the given weights.
// 4. Consider each vertex as an intermediate vertex.
// 5. Check whether the path through the intermediate vertex is shorter.
// 6. Update the distance if a shorter path exists.
// 7. Repeat for all intermediate vertices.
// 8. Display the final shortest-distance matrix.
// 9. Stop.

// T.C : O(V ^ 2) ; S.C : O(V ^ 2)

#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    int V;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v,wt});
    }

    void folydWarshall() {
        int INF = 1e9;

        // step-1 : Initialize the distance vector
        vector<vector<int>> dist(V, vector<int>(V, INF));

        // step-2 : Mark the self-distances as zero
        for(int i = 0; i < V; i++)
            dist[i][i] = 0;

        // step-3 : Mark all the remaining vertices
        for(int u = 0; u < V; u++) {
            for(auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;
                dist[u][v] = wt;
            }
        }

        // step-4 : Iterate k times to find the minimum edge wt for every v
        for(int k = 0; k < V; k++) {
            for(int i = 0; i < V; i++) {
                for(int j = 0; j < V; j++) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // main logic
            }
        }
        
        // Step-5 : Display the Graph 
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }

    }
};

int main() {
    int size, u, v, wt;

    cout << "Enter the required size of the graph : ";
    cin >> size;
    cout << endl;

    Graph g(size);

    for(int i = 0; i <= size; i++) {
        cout << "Enter the values of u,v and wt (" << i << "-vertex) : ";
        cin >> u >> v >> wt;
        g.addEdge(u,v,wt);
    }

    cout << "\nFinal Minimum Edge Weights : \n";
    g.folydWarshall();

    return 0;
}