#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<bool>> visited;
int capacity[3];
vector<int> answer;

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    answer.push_back(capacity[2]);
    visited[0][0] = true;
    int sender[6] = {0, 0, 1, 1, 2, 2};
    int receiver[6] = {1, 2, 0, 2, 0, 1};
    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();
        int statusA = now.first;
        int statusB = now.second;
        int statusC = capacity[2] - statusA - statusB;
        visited[statusA][statusB] = true;
        for (int i = 0; i < 6; i++) {
            int status[3] = {statusA, statusB, statusC};
            if (status[sender[i]] == 0) {
                continue;
            }

            if (status[sender[i]] + status[receiver[i]] > capacity[receiver[i]]) {
                int amount = capacity[receiver[i]] - status[receiver[i]];
                status[sender[i]] -= amount;
                status[receiver[i]] += amount;
            } else {
                status[receiver[i]] = status[sender[i]] + status[receiver[i]];
                status[sender[i]] = 0;
            }

            if (!visited[status[0]][status[1]]) {
                if (status[0] == 0 && find(answer.begin(), answer.end(), status[2]) == answer.end()) {
                    answer.push_back(status[2]);
                }
                q.emplace(status[0], status[1]);
            }
        }
    }
}

int main() {
    cin >> capacity[0] >> capacity[1] >> capacity[2];
    visited.assign(capacity[0] + 1, vector<bool>(capacity[1] + 1, false));
    bfs();
    sort(answer.begin(), answer.end());
    for (int a: answer) {
        cout << a << ' ';
    }
    return 0;
}