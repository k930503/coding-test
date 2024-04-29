#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000
using namespace std;

typedef pair<int, int> pii;
vector<vector<pii>> adjacentList;
vector<bool> visited;
vector<int> minDistance;

void dijkstra(int start, int end) {
    priority_queue<pii, vector<pii>, greater<>> pq;
    minDistance[start] = 0;
    pq.emplace(0, start);
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (cur == end) {
            break;
        }
        if (visited[cur]) {
            continue;
        }
        visited[cur] = true;
        for (pii next : adjacentList[cur]) {
            int nextVertex = next.second;
            int nextWeight = next.first;
            int distance = minDistance[cur] + nextWeight;
            if (minDistance[nextVertex] > distance) {
                minDistance[nextVertex] = distance;
                pq.emplace(minDistance[nextVertex], nextVertex);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adjacentList.assign(n + 1, vector<pii>(0));
    visited.assign(n + 1, false);
    minDistance.assign(n + 1, INF);
    for (int i = 0; i < m; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        adjacentList[src].emplace_back(cost, dst);
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
    cout << minDistance[end];
    return 0;
}