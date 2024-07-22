#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> point;

vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValidation(int x, int y, vector<string>& board) {
    if (x > -1 && y > -1 && x < board.size() && y < board[0].length()) {
        return true;
    }
    return false;
}

bool isD(int x, int y, vector<string>& board) {
    if (board[x][y] == 'D') {
        return true;
    }
    return false;
}

int bfs(point start, vector<string>& board) {
    queue<point> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int level = 0;
    int curSize = 1;
    int count = 0;
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        count++;
        if (board[current.first][current.second] == 'G') {
            return level;
        }
        
        for (int i = 0; i < 4; i++) {
            int nextX = current.first;
            int nextY = current.second;
            while (isValidation(nextX + dx[i], nextY + dy[i], board) && !isD(nextX + dx[i], nextY + dy[i], board)) {
                nextX = nextX + dx[i];
                nextY = nextY + dy[i];
            }
            
            if (!visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                point next = {nextX, nextY};
                q.push(next);
            }
        }
        
        if (count == curSize) {
            level++;
            cout << "level: " << level << endl;
            count = 0;
            curSize = (int)q.size();
        }
    }
    return -1;
}

point findStart(vector<string>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].length(); j++) {
            if (board[i][j] == 'R') {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int solution(vector<string> board) {
    int answer = 0;
    visited.assign(board.size(), vector<bool>(board[0].length(), false));
    point start = findStart(board);
    answer = bfs(start, board);
    return answer;
}