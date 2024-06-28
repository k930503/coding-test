#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int, int> pii;
vector<vector<pii>> adjacentList;
vector<bool> visited;
vector<int> minDistance;

void dijkstra(int start) {
    priority_queue <pii, vector<pii>, greater<>> pq;
    pq.emplace(0, start);
    minDistance[start] = 0;
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        for (pii next: adjacentList[cur]) {
            int nextVertex = next.second;
            int nextWeight = next.first;
            int distance = minDistance[cur] + nextWeight;
            if (distance < minDistance[nextVertex]) {
                minDistance[nextVertex] = distance;
                pq.emplace(minDistance[nextVertex], nextVertex);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;
    int start;
    cin >> start;
    adjacentList.assign(vertexCnt + 1, vector<pii>(0));
    visited.assign(vertexCnt + 1, false);
    minDistance.assign(vertexCnt + 1, INF);
    for (int i = 0; i < edgeCnt; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjacentList[u].emplace_back(w, v);
    }
    dijkstra(start);

    for (int i = 1; i <= vertexCnt; i++) {
        if (minDistance[i] == INF) {
            cout << "INF" << '\n';
        } else {
            cout << minDistance[i] << '\n';
        }
    }
    return 0;
}