#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> v;
queue<pair<int, int>> myqueue;
int n, m;

void bfs(pair<int, int> p) {
    pair<int, int> curNode = p;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!(curNode.first == n && curNode.second == m)) {
        int curNodeVal = v[curNode.first][curNode.second];
        for (int i = 0; i < 4; i++) {
            int nextX = curNode.first + dx[i];
            int nextY = curNode.second + dy[i];
            int* nextNode = &v[nextX][nextY];
            if (*nextNode == 1) {
                *nextNode += curNodeVal;
                myqueue.emplace(nextX, nextY);
            }
        }
        curNode = myqueue.front();
        myqueue.pop();
    }
    cout << v[n][m];
}

int main() {
    cin >> n >> m;
    // out of range를 막기위해 테두리를 0으로 두기 위해 +2 해줌.
    v.assign(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= m; j++) {
            v[i][j] = str[j - 1] - 48;
        }
    }

    bfs(make_pair(1,1));
    return 0;
}