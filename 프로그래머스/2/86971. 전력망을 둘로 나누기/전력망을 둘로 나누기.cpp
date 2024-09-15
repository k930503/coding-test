#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <climits>
using namespace std;

vector<bool> visited;
vector<vector<int>> adjacentList;

int bfs(int start) {
    int count = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        count++;
        for (int next: adjacentList[current]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    for (int i = 1; i < n; i++) {
        adjacentList.assign(n + 1, vector<int>(0));
        visited.assign(n + 1, false);
        for (int j = 0; j < wires.size(); j++) {
            if (j != i - 1) {
                adjacentList[wires[j][0]].push_back(wires[j][1]);
                adjacentList[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        int temp[2];
        int index = 0;
        for (int j = 1; j < n; j++) {
            if (!visited[j]) {
                temp[index++] = bfs(j);
            }
        }
        answer = min(answer, abs(temp[0] - temp[1]));
    }
    return answer;
}