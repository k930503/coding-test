#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited;

int bfs(int x, int y, int n) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    
    int level = 0;
    int count = 0;
    int curSize = 1;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;
        if (current == y) {
            return level;
        }
        int plusN = current + n;
        if (plusN <= y && !visited[plusN]) {
            q.push(plusN);
            visited[plusN] = true;
        }
        int x2 = current * 2;
        if (x2 <= y && !visited[x2]) {
            q.push(x2);
            visited[x2] = true;
        }
        int x3 = current * 3;
        if (x3 <= y && !visited[x3]) {
            q.push(x3);
            visited[x3] = true;
        }
        
        if (count == curSize) {
            count = 0;
            level++;
            curSize = q.size();
        }
    }
    return -1;
}

int solution(int x, int y, int n) {
    int answer = 0;
    visited.assign(y + 1, false);
    answer = bfs(x, y, n);
    return answer;
}