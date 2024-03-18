#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 10
int N, E;
int Graph[MAX_N][MAX_N];

void dfs(int node) {
    bool visited[MAX_N] = { false };

    stack<int> stack;
    stack.push(node);

    while(!stack.empty()) {
        int cur = stack.top();
        stack.pop();

        if (visited[cur]) {
            continue;
        }

        visited[cur] = true;

        cout << cur << " ";

        for (int next = 0; next < N; next++) {
            if (!visited[next] && Graph[cur][next]) {
                stack.push(next);
            }
        }
    }
}

int main() {
    // 5 6
    // 0 1 0 2 1 3 1 4 2 4 3 4
    cin >> N >> E;
    memset(Graph, 0, sizeof(Graph));

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u][v] = Graph[v][u] = 1;
    }
    dfs(0);
    return 0;
}