#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> a;
vector<int> visited;
vector<int> answer;
int n, m, k, x;

void bfs(int vertex) {
    queue<int> q;
    q.push(vertex);
    visited[vertex]++;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i : a[cur]) {
            if (visited[i] == -1) {
                q.push(i);
                visited[i] = visited[cur] + 1;
                if (visited[i] > k) {
                    return;
                } else if (visited[i] == k) {
                    answer.push_back(i);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k >> x;
    a.assign(n + 1, vector<int>(0, 0));
    visited.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int src, dst;
        cin >> src >> dst;
        a[src].push_back(dst);
    }
    bfs(x);
    if (answer.empty()) {
        cout << -1;
        return 0;
    }
    sort(answer.begin(), answer.end());
    for (int i : answer) {
        cout << i << '\n';
    }
    return 0;
}