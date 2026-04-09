#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> bellmanFord(int src, int V, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        bool updated = false;
        for (int j = 0; j < edges.size(); j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    // Detect negative-weight cycles
    for (int j = 0; j < edges.size(); j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative cycle detected!" << endl;
            return {};
        }
    }

    return dist;
}

int main() {
    int V = 5;
    vector<Edge> edges;

    edges.push_back({0, 1,  6});
    edges.push_back({0, 3,  7});
    edges.push_back({1, 2,  5});
    edges.push_back({1, 3,  8});
    edges.push_back({1, 4, -4});
    edges.push_back({2, 1, -2});
    edges.push_back({3, 2, -3});
    edges.push_back({3, 4,  9});
    edges.push_back({4, 0,  2});
    edges.push_back({4, 2,  7});

    vector<int> dist = bellmanFord(0, V, edges);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++)
        cout << "  to " << i << " = " << dist[i] << endl;
    // Output: to 0=0, to 1=2, to 2=4, to 3=7, to 4=-2
    cout <<"name - dev , roll no - 2401730237"<<endl;
    return 0;
}