#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    const int INF = numeric_limits<int>::max();
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> minIntensity(n + 1, INF);
    vector<bool> isSummit(n + 1, false);

    // 산봉우리 표시
    for (int summit : summits) {
        isSummit[summit] = true;
    }

    // 그래프 구성
    for (const auto& path : paths) {
        int i = path[0], j = path[1], w = path[2];
        graph[i].emplace_back(j, w);
        graph[j].emplace_back(i, w);
    }

    // 다익스트라 알고리즘
    auto dijkstra = [&]() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int gate : gates) {
            pq.emplace(0, gate);
            minIntensity[gate] = 0;
        }

        while (!pq.empty()) {
            int intensity = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (intensity > minIntensity[node]) continue;

            for (const auto& [nextNode, weight] : graph[node]) {
                int nextIntensity = max(intensity, weight);
                if (nextIntensity < minIntensity[nextNode] && !isSummit[node]) {
                    minIntensity[nextNode] = nextIntensity;
                    pq.emplace(nextIntensity, nextNode);
                }
            }
        }
    };

    dijkstra();

    // 최소 intensity 산봉우리 찾기
    int minSummit = -1;
    int minSummitIntensity = INF;
    for (int summit : summits) {
        if (minIntensity[summit] < minSummitIntensity) {
            minSummitIntensity = minIntensity[summit];
            minSummit = summit;
        } else if (minIntensity[summit] == minSummitIntensity && summit < minSummit) {
            minSummit = summit;
        }
    }

    return {minSummit, minSummitIntensity};
}
