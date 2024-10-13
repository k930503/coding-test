#include <string>
#include <vector>
using namespace std;

vector<vector<int>> v;

bool isEnd(int x, int y) {
    if (x >= 0 && y >= 0 && x < v.size() && y < v[x].size() && v[x][y] == 0) {
        return false;
    }
    return true;
}

vector<int> solution(int n) {
    v.assign(n, vector<int>(0));
    for (int i = 0; i < v.size(); i++) {
        v[i].assign(i + 1, 0);
    }
    vector<int> answer;
    int count = 0;
    int maximum = 0;
    for (int i = 1; i <= n; i++) {
        maximum += i;
    }
    int direction = 0; // 0: 밑, 1: 오른쪽, 2: 위
    int x = 0; int y = 0;
    while (count < maximum) {
        v[x][y] = ++count;
        if (direction == 0) {
            if (!isEnd(x + 1, y)) {
                x++;
            } else {
                y++;
                direction = (direction + 1) % 3;
            }
        } else if (direction == 1) {
            if (!isEnd(x, y + 1)) {
                y++;
            } else {
                x--; y--;
                direction = (direction + 1) % 3;
            }
        } else if (direction == 2) {
            if (!isEnd(x - 1, y - 1)) {
                x--; y--;
            } else {
                x++;
                direction = (direction + 1) % 3;
            }
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            answer.push_back(v[i][j]);
        }
    }
    return answer;
}