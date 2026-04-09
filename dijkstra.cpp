#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;

vector<int> dijkstra(int src, int V, vector<vector<pii>>& graph) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> graph(V);
    graph[0].push_back(make_pair(1, 4));
    graph[0].push_back(make_pair(2, 2));
    graph[1].push_back(make_pair(3, 3));
    graph[1].push_back(make_pair(2, 5));
    graph[2].push_back(make_pair(1, 1));
    graph[2].push_back(make_pair(3, 8));
    graph[2].push_back(make_pair(4, 10));
    graph[3].push_back(make_pair(4, 2));

    vector<int> dist = dijkstra(0, V, graph);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < V; i++)
        cout << "  to " << i << " = " << dist[i] << endl;
    // Output: 0->0=0, 0->1=3, 0->2=2, 0->3=6, 0->4=8
    return 0;
}