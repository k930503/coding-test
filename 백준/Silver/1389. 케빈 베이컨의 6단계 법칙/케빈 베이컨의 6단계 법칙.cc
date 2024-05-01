#include <iostream>
#include <vector>
#include <climits>
#define INF 98
using namespace std;

vector<vector<int>> adjacencyMatrix;
int n, m;

void floydwarshall() {
    for (int k = 1; k <= n; k++) {
        for (int src = 1; src <= n; src++) {
            for (int dst = 1; dst <= n; dst++) {
                adjacencyMatrix[src][dst] = min(adjacencyMatrix[src][dst], adjacencyMatrix[src][k] + adjacencyMatrix[k][dst]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> m;
    adjacencyMatrix.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1;
    }
    floydwarshall();
    int temp = INT_MAX;
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += adjacencyMatrix[i][j];
        }
        if (sum < temp) {
            temp = sum;
            answer = i;
        }
    }
    cout << answer;
    return 0;
}
