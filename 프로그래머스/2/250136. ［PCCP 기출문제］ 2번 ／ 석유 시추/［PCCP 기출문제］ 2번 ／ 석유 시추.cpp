#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

typedef pair<int, int> point;

int n, m;
int oilAreaId = -1;
vector<int> oilAmounts;
vector<vector<int>> visited;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void bfs(int x, int y, vector<vector<int>>& land) {
    queue<point> q;
    point p = {x, y};
    q.push(p);
    visited[x][y] = oilAreaId;
    int count = 0;
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        count++;
        for (int i = 0; i < 4; i++) {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if (nextX > -1 && nextY > -1 && nextX < n && nextY < m) {
                if (visited[nextX][nextY] == -1 && land[nextX][nextY] == 1) {
                    point nextP = {nextX, nextY};
                    q.push(nextP);
                    visited[nextX][nextY] = oilAreaId;
                }
            }
        }
    }
    visited[x][y] = oilAreaId;
    oilAmounts.push_back(count);
}

int solution(vector<vector<int>> land) {
    n = land.size();
    m = land[0].size();
    int answer = 0;
    visited.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == -1 && land[i][j] == 1) {
                oilAreaId++;
                bfs(i, j, land);
            }
        }
    }
    
    for (int i = 0; i < oilAmounts.size(); i++) {
        cout << oilAmounts[i] << " ";
    }
    for (int i = 0; i < m; i++) {
        int currentAmount = 0;
        unordered_set<int> uset;
        for (int j = 0; j < n; j++) {
            int id = visited[j][i];
            if (id == -1 || uset.find(id) != uset.end()) {
                continue;
            }
            uset.insert(id);
            currentAmount += oilAmounts[id];
        }
        answer = max(answer, currentAmount);
    }
    return answer;
}