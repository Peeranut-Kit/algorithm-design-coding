#include <iostream>
#include <graph.h>
#include <vector>
using namespace std;

// Disjoint set makes set of every vertexs to be different sets of 1 memeber
// Each element must be in exactly one set
class disjointSet
{
private:
    vector<int> p;
    vector<int> t_size;
public:
    disjointSet();
    ~disjointSet();

    // array p where p[x] is the parent of node x, p[x] = -1 if x is a root
    // array t_size is size of tree
    // create n sets for element 1...n, each set contains each element.
    int makeset(graph G)
    {
        for (size_t i = 0; i < G.node_size(); i++)
        {
            p[i] = -1;
            t_size[i] = 1;
        }
    }

    // return the root of a set where x is a member. If two vertrices are in the same set, return equal number
    // O(logv)
    int findset(int x)
    {
        if (p[x] == -1) return x;
        return findset(x);
    }

    // union the set findset(x) with the set findset(y)
    // Make root of less height set points to taller height set root
    // That makes tree height equals log(v) all the way
    // O(2logv) => O(logv)
    void union_set(int x, int y) {
        int s1 = findset(x);
        int s2 = findset(y);
        if (t_size[s1] < t_size[s2]) {
            p[s1] = s2;
            t_size[s2] += t_size[s1];
        }
        else {
            p[s2] = s1;
            t_size[s1] += t_size[s2];
        }
    }
};

// Select the minimal edge of all edges that does not create a cycle
// Sort edges in increasing order weight => O(eloge)
// loop edges => e iterations
// find_set => O(logv)
// Union set => O(logv)
// O(eloge) + e x O(log(v)) => O(eloge + elogv)
vector< pair<int,int> > Kruskal(graph G) {
    disjointSet ds = disjointSet();
    ds.makeset(G);
    
    vector< pair<int,int> > ans = {};
    vector< pair<int,int> > sorted_edge = G.get_sorted_edge();
    for ( auto pair : sorted_edge ) {
        if (ds.findset(pair.first) != ds.findset(pair.second)) {
            ans.push_back(pair);
            ds.union_set(pair.first, pair.second);
        }
    }
    return ans;
}