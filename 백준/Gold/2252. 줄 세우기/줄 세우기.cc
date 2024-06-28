#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adjacentList;
vector<int> in;
vector<int> answer;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adjacentList.assign(n + 1, vector<int>(0));
    in.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacentList[a].push_back(b);
        in[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int src = q.front();
        q.pop();
        answer.push_back(src);
        for (int dst : adjacentList[src]) {
            if (--in[dst] == 0) {
                q.push(dst);
            }
        }
    }

    for (int a: answer) {
        cout << a << ' ';
    }
    return 0;
}