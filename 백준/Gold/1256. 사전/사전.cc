#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + m + 1, vector<int>(n + m + 1, 0));
    for (int i = 0; i <= n + m; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for (int i = 3; i <= n + m; i++) {
        for (int j = 2; j <= n + m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            if (dp[i][j] > 1000000000) {
                dp[i][j] = 1000000001;
            }
        }
    }

    if (dp[n + m][n] < k) {
        cout << -1;
        return 0;
    }

    string answer;
    int a = n;
    int z = m;
    while (answer.length() < n + m) {
        int t = dp[a + z - 1][a - 1];
        if (t >= k) {
            answer += 'a';
            a--;
        } else {
            answer += 'z';
            z--;
            k -= t;
        }
    }
    cout << answer;
    return 0;
}