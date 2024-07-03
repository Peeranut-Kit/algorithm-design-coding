#include <iostream>
#include <graph.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// O(n + e)
void find_path_dfs(int a, graph &G, vector<bool> &visited, vector<int> &from, stack<int> &s) {
    s.push(a);
    visited[a] = true;
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        for (auto b: G.adj(e)) {
            if (visited[b] == false) {
                visited[b] = true;
                from[b] = e;
                s.push(b);
            }
        }
    } 
}

// O(n + e)
void find_path_bfs(int a, graph &G, vector<bool> &visited, vector<int> &from, queue<int> &q) {
    q.push(a);
    visited[a] = true;
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        for (auto b: G.adj(e)) {
            if (visited[b] == false) {
                visited[b] = true;
                from[b] = e;
                q.push(b);
            }
        }
    } 
}

// O(n + e)
void distance_bfs(int a, graph &G, queue<int> &q, vector<int> &dist) {
    q.push(a);
    dist[a] = 0;
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        for (auto b: G.adj(e)) {
            if (dist[b] == -1) {
                dist[b] = dist[e] + 1;
                q.push(b);
            }
        }
    } 
}

// O(n + e)
void cc_dfs(int u, graph &G, vector<int> &visited, stack<int> &s, int cc_num) {
    s.push(u);
    visited[u] = cc_num;
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        for (auto b: G.adj(e)) {
            if (visited[b] == 0) {
                visited[b] = cc_num;
                s.push(b);
            }
        }
    } 
}

void cc(graph G) {
    int cc_num = 0;
    vector<int> visited(G.node_size());
    stack<int> s;
    for (auto u: G.get_vertex()) {
        if (visited[u] == 0) {
            cc_num += 1;
            cc_dfs(u, G, visited, s, cc_num);
        }
    }
}

// O(n + e)
bool circuit_detection_dfs(int u, graph &G, vector<bool> &visited, stack<int> &s, int parent) {
    s.push(u);
    visited[u] = true;
    while (!s.empty()) {
        int e = s.top();
        s.pop();
        for (auto b: G.adj(e)) {
            if (visited[b] == 0) {
                s.push(b);
            }
            else if (b != parent) { // Check if it is not the same edge that traveled from.
                return true;
            }
        }
    } 
    return false;
}

bool circuit_detection(graph G) {
    vector<bool> visited(G.node_size());
    stack<int> s;
    for (auto u: G.get_vertex()) {
        if (visited[u] == false) {
            if (circuit_detection_dfs(u, G, visited, s, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int u, n;
    graph G;
    vector<bool> visited(n);
    vector<int> from(n, -1);
    stack<int> s;
    vector<int> distance(n, -1);
    find_path_dfs(u, G, visited, from, s);
    return 0;
}
