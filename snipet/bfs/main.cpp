#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_N 10
int N, E;
int Graph[MAX_N][MAX_N];

void bfs(int node) {
    bool visited[MAX_N] = { false };

    queue<int> queue;
    visited[node] = true;
    queue.push(node);

    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();

        cout << cur << " ";

        for (int next = 0; next < N; next++) {
            if (!visited[next] && Graph[cur][next]) {
                visited[next] = true;
                queue.push(next);
            }
        }
    }
}

int main() {
    // 5 6
    // 0 1 0 2 1 3 1 4 2 4 3 4
    cin >> N >> E;
    memset(Graph, 0, sizeof(Graph));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u][v] = Graph[v][u] = 1;
    }
    bfs(0);
    return 0;
}