#include <iostream>
#include <graph.h>
#include <vector>
#include <set>
using namespace std;

// Overall same as Prim => O((n+e)logn)
// Does not work correctly on negative edges graph
vector<int> Dijkstra_onesource(graph G, int u) {
    int node_size = G.node_size();
    vector<int> dist(node_size, INT_MAX); // answer vector
    vector<int> prev(node_size, -1);

    // set contains pair of <weight, connectible node> order from lower weight to higher
    set< pair<int,int> > s;
    int initial_node = G.get_vertex()[0];
    s.insert(make_pair(0, initial_node));
    while (!s.empty())
    {
        auto min_edge = *s.begin();
        s.erase(min_edge); // or s.erase(s.begin())
        int T = min_edge.first;
        int u = min_edge.second;
        for (auto v: G.adj(u)) {
            int w = G.get_weight(u,v);
            if (T + w < dist[v])
            {
                if(s.find({dist[v], v}) != s.end()) s.erase({dist[v], v}); // remove if exists
                dist[v] = w;
                prev[v] = u;
                s.insert({dist[v], v});
            }
        }
    }
    return dist;
}