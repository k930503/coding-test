#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define RED 1
#define BLUE 2

vector<vector<int>> graph;
vector<bool> visited;
vector<int> colors;

bool bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    colors[vertex] = RED;
    visited[vertex] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur]) {
            if (visited[next]) {
                if (colors[next] == colors[cur]) {
                    return false;
                }
                continue;
            }
            q.push(next);
            visited[next] = true;
            if (colors[cur] == RED) {
                colors[next] = BLUE;
            } else {
                colors[next] = RED;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int vertex, edge;
        cin >> vertex >> edge;
        graph.assign(vertex + 1, vector<int>(0));
        visited.assign(vertex + 1, false);
        colors.assign(vertex + 1, 0);
        for (int j = 0; j < edge; j++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int isBipartite = true;
        for (int j = 1; j <= vertex; j++) {
            if (!visited[j]) {
                if (!bfs(j)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (isBipartite) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}