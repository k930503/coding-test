#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> point;

vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValidation(int x, int y, vector<string>& maps) {
    if (x > -1 && y > -1 && x < maps.size() && y < maps[0].length() && maps[x][y] != 'X') {
        return true;
    }
    return false;
}

int bfs(int startX, int startY, vector<string>& maps) {
    queue<point> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    int sum = 0;
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        sum += maps[current.first][current.second] - 48;
        for (int i = 0; i < 4; i++) {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if (isValidation(nextX, nextY, maps) && !visited[nextX][nextY]) {
                q.push({ nextX, nextY });
                visited[nextX][nextY] = true;
            }
        }
    }
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].length(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(bfs(i, j, maps));
            }
        }
    }
    sort(answer.begin(), answer.end());
    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}