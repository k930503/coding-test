#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            sum[i][j] = arr[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    // 횟수 돌면서 output.
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
    }
    return 0;
}