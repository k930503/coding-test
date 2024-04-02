#include <iostream>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> v;
queue<pair<int, int>> myqueue;
int n, m;

void bfs(pair<int, int> p) {
    pair<int, int> curNode = p;

    while (!(curNode.first == n && curNode.second == m)) {
        int curNodeVal = v[curNode.first][curNode.second];
        int* top = &v[curNode.first - 1][curNode.second];
        int* bottom = &v[curNode.first + 1][curNode.second];
        int* left = &v[curNode.first][curNode.second - 1];
        int* right = &v[curNode.first][curNode.second + 1];

        if (*top == 1) {
            *top += curNodeVal;
            myqueue.emplace(curNode.first - 1, curNode.second);
        }
        if (*bottom == 1) {
            *bottom += curNodeVal;
            myqueue.emplace(curNode.first + 1, curNode.second);
        }
        if (*left == 1) {
            *left += curNodeVal;
            myqueue.emplace(curNode.first, curNode.second - 1);
        }
        if (*right == 1) {
            *right += curNodeVal;
            myqueue.emplace(curNode.first, curNode.second + 1);
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