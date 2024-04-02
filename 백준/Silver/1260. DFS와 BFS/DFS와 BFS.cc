#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> adjacentList;
vector<bool> visited;

void dfs(int num) {
    cout << num << ' ';
    visited[num] = true;
    for (int next : adjacentList[num]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int num) {
    fill(visited.begin(), visited.end(), false);

    queue<int> myqueue;
    myqueue.push(num);

    visited[num] = true;

    while (!myqueue.empty()) {
        int cur = myqueue.front();
        myqueue.pop();
        cout << cur << ' ';
        for (int next : adjacentList[cur]) {
            if (!visited[next]) {
                myqueue.push(next);
                visited[next] = true;
            }
        }
    }
}
void insert(int at, int num) {
    auto it = adjacentList[at].begin();
    if (!adjacentList[at].empty()) {
        int index = -1;
        for (int j = 0; j < adjacentList[at].size(); j++) {
            if (adjacentList[at][j] > num) {
                index = j;
                break;
            }
        }
        if (index > -1) {
            adjacentList[at].insert(it + index, num);
        } else {
            adjacentList[at].push_back(num);
        }
    } else {
        adjacentList[at].push_back(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, v;
    cin >> n >> m >> v;

    adjacentList.assign(n + 1, vector<int>(0, 0));
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        insert(v1, v2);
        insert(v2, v1);
    }
    dfs(v);
    cout << '\n';
    bfs(v);
    return 0;
}
