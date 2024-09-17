#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> position;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

bool bfs(position start, vector<string>& room) {
    bool visited[5][5] = { false };
    queue<position> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int curSize = 1;
    int level = 0;
    int count = 0;
    while (!q.empty()) {
        position current = q.front();
        q.pop();
        count++;
        if (level > 0 && room[current.first][current.second] == 'P') {
            return false;
        }
        for (int i = 0; i < 4; i++) {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if (nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5 && !visited[nextX][nextY] && room[nextX][nextY] != 'X' && level < 2) {
                q.emplace(nextX, nextY);
                visited[nextX][nextY] = true;
            }
        }
        if (count == curSize) {
            count = 0;
            level++;
            curSize = q.size();
        }
    }
    return true;
}

bool isRoomEligible(vector<string>& room) {
    for (int i = 0; i < room.size(); i++) {
        for (int j = 0; j < room[i].length(); j++) {
            if (room[i][j] == 'P') {
                if (!bfs({i, j}, room)) {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < places.size(); i++) {
        bool isFollowed = isRoomEligible(places[i]);
        answer.push_back(isFollowed);
    }
    return answer;
}