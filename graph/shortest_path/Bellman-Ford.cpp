#include <iostream>
#include <graph.h>
#include <vector>
using namespace std;

// Deal with negative edges graph
// D(a,v) = min( D(a-1,v), min(D(a-1,u) + w(u,v)) )
// O(ne) where Dijksta is O(elogn)
// Graph denseness O(n^3) where Dijksta is O(n^2logn)
vector<int> Bellman_Ford(graph G, int u) {
    int node_size = G.node_size();
    vector<int> dist(node_size, INT_MAX); // answer vector
    vector<int> prev(node_size, -1);

    dist[u] = 0;
    for (size_t i = 1; i < node_size-1; i++)
    {
        for (auto p : G.get_edge()) {
            int a = p.first;
            int b = p.second;
            if (dist[b] > dist[a] + G.get_weight(a,b)) {
                dist[b] = dist[a] + G.get_weight(a,b);
                prev[b] = a;
            }
        }
    }
    for (auto p : G.get_edge()) {
        int a = p.first;
        int b = p.second;
        if (dist[b] > dist[a] + G.get_weight(a,b)) {
            throw "negative cycle";
        }
    }
    return dist;
}