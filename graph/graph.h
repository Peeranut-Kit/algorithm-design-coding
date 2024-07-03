#include <vector>
using namespace std;

class graph
{
private:
    vector<int> vertex;
    vector< vector<int> > edge_matrix;
    vector< pair<int,int> > pair_of_adjacent_node;

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

    int get_weight(int u, int v) {
        return edge_matrix[u][v];
    }

    void remove_edge(int u, int v) {
        return;
    }

    bool has_edge() {
        return true;
    }

    vector< pair<int,int> > get_edge() {
        return pair_of_adjacent_node;
    }

    vector< pair<int,int> > get_sorted_edge() {
        return pair_of_adjacent_node;
    }
};