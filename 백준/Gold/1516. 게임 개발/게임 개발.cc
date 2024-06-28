#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> adjacentList(n + 1, vector<int>(0));
    vector<int> inDegree(n + 1, 0);
    vector<int> time(n + 1, 0);
    vector<int> answer(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        bool isTime = true;
        while (true) {
            int input;
            cin >> input;
            if (input == -1) {
                break;
            }
            if (isTime) {
                time[i] = input;
                answer[i] = input;
                isTime = false;
            } else {
                adjacentList[input].push_back(i);
                inDegree[i]++;
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next: adjacentList[cur]) {
            if (--inDegree[next] == 0) {
                q.push(next);
            }
            answer[next] = max(answer[next], answer[cur] + time[next]);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}