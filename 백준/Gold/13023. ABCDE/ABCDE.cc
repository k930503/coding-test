#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> visited;
int depth = 0;

bool dfs(int num) {
    depth++;
    if (visited[num]) {
        depth--;
        return false;
    }

    if (depth == 5) {
        return true;
    }

    visited[num] = true;

    for (int i = 0; i < v[num].size(); i++) {
        int adjacentNum = v[num][i];
        if (visited[adjacentNum]) {
            continue;
        }
        if (dfs(adjacentNum)) {
            return true;
        };
    }
    visited[num] = false;
    depth--;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    v.assign(n, vector<int>(0, 0));
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++) {
        if (dfs(i)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
