#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacencyList;
vector<bool> visited;
vector<int> answer;

void dfs(int node) {
    visited[node] = true;
    for (int next : adjacencyList[node]) {
        if (!visited[next]) {
            answer[next] = node;
            dfs(next);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    adjacencyList.assign(n + 1, vector<int>(0));
    visited.assign(n + 1, false);
    answer.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}