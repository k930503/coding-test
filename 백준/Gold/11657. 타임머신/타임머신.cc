#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edgeList;
vector<long long> minDistance;
int n, m;

bool bellmanFord(int start) {
    minDistance[start] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int src = get<0>(edgeList[j]);
            int dst = get<1>(edgeList[j]);
            int weight = get<2>(edgeList[j]);
            long long distance = minDistance[src] + weight;
            if (minDistance[src] != LONG_MAX && minDistance[dst] > distance) {
                if (i == n - 1) {
                    return false;
                }
                minDistance[dst] = distance;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    edgeList.resize(m);
    minDistance.assign(n + 1, LONG_MAX);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList[i] = make_tuple(a, b, c);
    }

    if (!bellmanFord(1)) {
        cout << -1;
        return 0;
    }


    for (int i = 2; i <= n; i++) {
        if (minDistance[i] == LONG_MAX) {
            cout << -1 << '\n';
        } else {
            cout << minDistance[i] << '\n';
        }
    }
    return 0;
}