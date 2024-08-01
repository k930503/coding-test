#include <string>
#include <vector>

using namespace std;

int maxRound = 0;

void backtrack(int depth, int current, int k, vector<vector<int>>& dungeons, vector<bool> visited) {
    visited[current] = true;
    if (k < dungeons[current][0]) {
        maxRound = max(maxRound, depth);
        return;
    }
    for (int i = 0; i < dungeons.size(); i++) {
        if (!visited[i]) {
            backtrack(depth + 1, i, k - dungeons[current][1], dungeons, visited);
        }
    }
    maxRound = max(maxRound, depth + 1);
}

int solution(int k, vector<vector<int>> dungeons) {
    for (int i = 0; i < dungeons.size(); i++) {
        int depth = 0;
        vector<bool> visited(dungeons.size(), false);
        backtrack(depth, i, k, dungeons, visited);
    }
    return maxRound;
}