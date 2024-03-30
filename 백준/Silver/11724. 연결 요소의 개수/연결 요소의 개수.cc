#include <iostream>
#include <vector>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;

void dfs(int cur) {
    visited[cur] = true;

    // 현재 정점과 간선으로 연결되어 있는 모든 정점들을 둘러본다.
    for(int i = 0; i < graph[cur].size(); i++){
        int next = graph[cur][i];
        // 만일 방문하지 않았다면 매개변수로 전달하여 DFS를 재귀적으로 호출한다.
        if(!visited[next]){
            dfs(next);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    visited.assign(n + 1, false);
    graph.assign(n + 1, vector<int>(0, 0));

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            answer++;
            dfs(i);
        }
    }
    cout << answer;
    return 0;
}
