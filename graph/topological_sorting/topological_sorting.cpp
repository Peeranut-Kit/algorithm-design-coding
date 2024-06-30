#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class graph
{
private:
    vector<int> vertex;
    vector< vector<int> > edge_matrix;
public:
    graph();
    ~graph();
    vector<int> adj(int vertex) {
        return {};
    }

    int node_size() {
        return vertex.size();
    }

    vector<int> get_vertex() {
        return vertex;
    }

    vector<int> zero_in_degree_node() {
        return vertex;
    }

    bool has_zero_in_degree(int v) {
        return true;
    }

    void remove_edge(int u, int v) {
        return;
    }

    bool has_edge() {
        return true;
    }
};

// O(n + e)
vector<int> topo_sorting(graph G) {
    vector<int> ans;
    queue<int> q;
    // There must be nodes with in-degree of 0
    for (auto z: G.zero_in_degree_node()) {
        q.push(z);
    }
    while(!q.empty()) {
        int e = q.front();
        q.pop();
        ans.push_back(e);
        for (auto v: G.adj(e)) {
            G.remove_edge(e, v);
            if (G.has_zero_in_degree(v)) {
                q.push(v);
            }
        }
    }
    // If the graph is directed acyclic graph, after while loop, there must be no edge left.
    if (!G.has_edge()) {
        // return error_code;
    }
    return ans;
}