#include <iostream>
#include <graph.h>
#include <vector>
#include <set>
using namespace std;

// Select the minimal node & edge of all edges that connects to the original graph
// stop when we have n nodes and n-1 edges
// initialization => O(n), while loop => n-1, find min and delete => log(n), inside for loop => log(n) e times. n + (n-1)logn + elogn
// Overall => O((n+e)logn)
vector<int> Prim(graph G) {
    int vertex_size = G.node_size();
    vector<int> cost(vertex_size, INT_MAX);
    vector<int> prev(vertex_size, -1); // answer vector
    vector<bool> taken(vertex_size, false);

    // set contains pair of <weight, connectible node> order from lower weight to higher
    set< pair<int,int> > s;
    int initial_node = G.get_vertex()[0];
    s.insert(make_pair(0, initial_node));
    while (!s.empty())
    {
        auto min_edge = *s.begin();
        s.erase(min_edge); // or s.erase(s.begin())
        int min_weight = min_edge.first;
        int u = min_edge.second;
        taken[u] = true;
        for (auto v: G.adj(u)) {
            int w = G.get_weight(u,v);
            if (taken[v] == false && w < cost[v])
            {
                if(s.find({cost[v], v}) != s.end()) s.erase({cost[v], v});  // remove if exists
                cost[v] = w;
                taken[v] = true;
                prev[v] = u;
                s.insert({cost[v], v});
            }
        }
    }
    return prev;
}

// Better Prim implementation by priority_queue or Fibonacci Heap to support decrease(top and decrease in O(1))