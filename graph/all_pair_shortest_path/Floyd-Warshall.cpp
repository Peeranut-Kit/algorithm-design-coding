#include <iostream>
#include <graph.h>
#include <vector>
using namespace std;

// If Dijkstra and Bellman-Ford are run for n times
// Dijkstra is O(nelogn), Bellman-Ford is O(nen) where e can be up to n^2 on dense graph
// Floyd-Warshall does it in O(n^3)
vector<vector<int>> Floyd_Warshall(graph G)
{
    int n = G.node_size();
    vector<vector<int>> dist;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; i++)
        {
            dist[i][j] = G.get_weight(i, j);
        }
    }
    for (size_t z = 0; z < n; z++)
    {
        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < n; x++)
            {
                dist[y][x] = min(dist[y][x], dist[y][z] + dist[z][x]);
            }
        }
    }
}