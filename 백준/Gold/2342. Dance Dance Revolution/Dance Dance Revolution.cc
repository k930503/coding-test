#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int dp[100001][5][5];

int getCost(int from, int to) {
    if (from == to) {
        return 1;
    } else if (from == 0) {
        return 2;
    } else if (abs(from - to) == 2) {
        return 4;
    } else {
        return 3;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    for (int i = 0; i < 100001; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i][j][k] = 100001 * 4;
            }
        }
    }
    dp[0][0][0] = 0;
    int current = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        current++;
        for (int i = 0; i <= 4; i++) {
            if (i == n) {
                continue;
            }
            for (int j = 0; j <= 4; j++) {
                dp[current][n][i] = min(dp[current][n][i], dp[current - 1][j][i] + getCost(j, n));
            }
        }
        for (int i = 0; i <= 4; i++) {
            if (i == n) {
                continue;
            }
            for (int j = 0; j <= 4; j++) {
                dp[current][i][n] = min(dp[current][i][n], dp[current - 1][i][j] + getCost(j, n));
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            answer = min(answer, dp[current][i][j]);
        }
    }
    cout << answer;
    return 0;
}