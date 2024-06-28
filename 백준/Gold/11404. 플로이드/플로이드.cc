#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

vector<vector<long long>> a;
int n, m;

void floydWarshall() {
    for (int k = 1; k <= n; k++) {
        for (int src = 1; src <= n; src++) {
            for (int dst = 1; dst <= n; dst++) {
                a[src][dst] = min(a[src][dst], a[src][k] + a[k][dst]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    a.assign(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        a[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        if (a[src][dst] > cost) {
            a[src][dst] = cost;
        }
    }

    floydWarshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == INF) {
                cout << 0 << ' ';
            } else {
                cout << a[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}