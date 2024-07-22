#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> point;

vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isGoal(int x, int y, char target, vector<string>& maps) {
    if (maps[x][y] == target) {
        return true;
    }
    return false;
}

bool isValidation(int x, int y, vector<string>& maps) {
    if (x > -1 && y > -1 && x < maps.size() && y < maps[0].length() && maps[x][y] != 'X') {
        return true;
    }
    return false;
}

int bfs(int startX, int startY, char target, vector<string>& maps) {
    queue<point> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    
    int level = 0;
    int count = 0;
    int curSize = 1;
    
    while (!q.empty()) {
        point current = q.front();
        q.pop();
        count++;
        if (isGoal(current.first, current.second, target, maps)) {
            return level;    
        }
        
        for (int i = 0; i < 4; i++) {
            int nextX = current.first + dx[i];
            int nextY = current.second + dy[i];
            if (isValidation(nextX, nextY, maps) && !visited[nextX][nextY]) {
                q.push({ nextX, nextY });
                visited[nextX][nextY] = true;
            }
        }
        if (count == curSize) {
            count = 0;
            level++;
            curSize = q.size();
        }
    }
    return -1;
}

point findStart(char target, vector<string>& maps) {
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0 ; j < maps[0].length(); j++) {
            if (maps[i][j] == target) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}

int solution(vector<string> maps) {
    int answer = 0;
    visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
    point start = findStart('S', maps);
    int destination1 = bfs(start.first, start.second, 'L', maps);
    if (destination1 == -1) {
        return -1;
    }
    
    visited.assign(maps.size(), vector<bool>(maps[0].length(), false));
    start = findStart('L', maps);
    int destination2 = bfs(start.first, start.second, 'E', maps);
    if (destination2 == -1) {
        return -1;
    }
    answer = destination1 + destination2;
    return answer;
}