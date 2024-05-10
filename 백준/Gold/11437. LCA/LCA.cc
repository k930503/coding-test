#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> depth;
vector<int> parent;

void bfs(int start) {
    int level = 1;
    int count = 0;
    int curDepthSize = 1;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        count++;
        depth[cur] = level;
        for (int next : tree[cur]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = cur;
            }
        }
        if (count == curDepthSize) {
            level++;
            count = 0;
            curDepthSize = (int)q.size();
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (depth[a] != depth[b]) {
        a = parent[a];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    tree.assign(n + 1, vector<int>(0)); // resize만해도 되는지
    visited.assign(n + 1, false);
    depth.resize(n + 1);
    parent.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    bfs(1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}