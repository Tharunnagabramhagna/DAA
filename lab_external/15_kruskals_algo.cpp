// 15. Implement Kruskal’s algorithm to find the Minimum spanning tree

// Algorithm
// 1. Start.
// 2. Read the number of vertices and edges.
// 3. Read the edges and their weights.
// 4. Sort all edges in ascending order of weight.
// 5. Select the smallest edge.
// 6. Check whether adding the edge creates a cycle.
// 7. If it does not create a cycle, include it in the Minimum Spanning Tree.
// 8. Repeat until V−1 edges are selected or all edges are checked.
// 9. Display the MST and its total cost.
// 10. Stop.

// T.C : O(E log E) ; S.C : O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int wt;
    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    // comparator => "<"
    bool operator<(const Edge &obj) const
    {
        return this->wt < obj.wt;
    }
};

class Graph
{
public:
    int V;
    vector<Edge> edges;
    vector<int> par, rank;
    Graph(int V)
    {
        this->V = V;
        for (int i = 0; i < V; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(int u, int v, int wt)
    {
        edges.push_back(Edge(u, v, wt));
    }

    int find(int x)
    {
        // Base Case
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]); // path compression
    }

    void unionFind(int a, int b)
    {
        int parA = find(a);
        int parB = find(b);

        // Edge Case => used for cycle detection too
        if (parA == parB)
            return;

        if (rank[parA] == rank[parB])
        {
            par[parB] = parA;
            rank[parA]++;
        }
        else if (rank[parA] > rank[parB])
            par[parB] = parA;
        else
            par[parA] = parB;
    }

    void kruskal()
    { // O(E logE)
        // sort the edges
        sort(edges.begin(), edges.end());
        int mstCost = 0; // store result
        int count = 0;

        for (int i = 0; i < edges.size() && count < V - 1; i++)
        {
            Edge e = edges[i]; // the edges
            // parents of u and v
            int parU = find(e.u);
            int parV = find(e.v);
            if (parU != parV)
            {
                unionFind(parU, parV); // linking to min wt vertices
                mstCost += e.wt;       // Adding of wt
                count++;               // optimization till V-1 edges
            }
        }

        cout << "Cost of MST : " << mstCost << endl;
    }
};

int main()
{
    // Kruskal's Algorithm

    Graph g(4);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(3, 2, 4);
    g.addEdge(0, 3, 5);
    g.addEdge(0, 2, 6);

    cout << "\n--Kruskal's Algorithm--\n";
    g.kruskal();
    cout << endl;

    return 0;
}