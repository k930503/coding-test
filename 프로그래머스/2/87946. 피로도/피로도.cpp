#include <string>
#include <vector>

using namespace std;

int maxRound = 0;
vector<bool> visited;

void dfs(int depth, int k, vector<vector<int>>& dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(depth + 1, k - dungeons[i][1], dungeons);
            visited[i] = false;
        }
    }
    maxRound = max(maxRound, depth);
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.assign(dungeons.size(), false);
    dfs(0, k, dungeons);
    return maxRound;
}