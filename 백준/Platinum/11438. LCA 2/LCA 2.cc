#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
vector<int> depth;
vector<vector<int>> parent;
int maxK = -1;

void bfs(int start) {
    int level = 1;
    int count = 0;
    int curDepthSize = 1;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[0][start] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        depth[cur] = level;
        count++;
        for (int next : tree[cur]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                parent[0][next] = cur;
            }
        }
        if (count == curDepthSize) {
            level++;
            curDepthSize = (int)q.size();
            count = 0;
        }
    }
}

int lca2(int a, int b) {
    if (depth[a] > depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    for (int k = maxK; k >= 0; k--) {
        if (pow(2, k) <= depth[b] - depth[a]) {
            b = parent[k][b];
        }
    }
    for (int k = maxK; k >= 0 && a != b; k--) {
        if (parent[k][a] != parent[k][b]) {
            a = parent[k][a];
            b = parent[k][b];
        }
    }

    int lca = a;
    if (a != b) {
        lca = parent[0][a];
    }
    return lca;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    tree.assign(n + 1, vector<int>(0));
    visited.assign(n + 1, false);
    depth.resize(n + 1);

    int temp = 1;
    while (temp <= n) {
        maxK++;
        temp <<= 1;
    }
    parent.assign(maxK + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n - 1; i++) {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    bfs(1);

    for (int i = 1; i <= maxK; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca2(a, b) << '\n';

    }
    return 0;
}