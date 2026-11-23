// 16. Implement Prim’s algorithm to find the Minimum spanning tree

// Algorithm
// 1. Start.
// 2. Read the number of vertices and adjacency matrix.
// 3. Select a starting vertex.
// 4. Initialize all vertices as unvisited.
// 5. Select the minimum-weight edge connecting a visited vertex to an unvisited vertex.
// 6. Add that edge to the MST.
// 7. Mark the new vertex as visited.
// 8. Repeat until all vertices are included.
// 9. Display the MST and total cost.
// 10. Stop.

// T.C : O(V^2) ; S.C : O(V^2)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int primAlgo(int src, int V, vector<vector<pair<int, int>>> &adj)
{
    vector<bool> mstSet(V, false);
    int mstCost = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // [wt, u]

    while (pq.size() > 0)
    {
        auto p = pq.top();

        int wt = p.first;
        int u = p.second;
        pq.pop();

        if (!mstSet[u])
        {
            mstSet[u] = true;
            mstCost += wt;
            
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (!mstSet[v])
                    pq.push({w, v});
            }
        }
    }

    return mstCost;
}

int main()
{
    int V = 5;
    vector<vector<pair<int, int>>> adj(V); // [v, wt]

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});

    adj[1].push_back({3, 40});
    adj[3].push_back({1, 40});

    adj[2].push_back({0, 15});
    adj[0].push_back({2, 15});

    adj[3].push_back({0, 30});
    adj[0].push_back({3, 30});

    adj[3].push_back({2, 50});
    adj[2].push_back({3, 50});

    cout << "Minimum spanning cost of the graph : " << primAlgo(0, V, adj);

    return 0;
}