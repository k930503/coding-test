#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        string input;
        cin >> input;
        for (int j = 1; j <= m; j++) {
            a[i][j] = input[j - 1] - '0';
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 1) {
                continue;
            }

            int temp = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            if (temp == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = temp;
            }
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer * answer;
    return 0;
}