#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int dp[1000001] = {0};
    dp[1] = 0;
    for (int i = 2; i <= 1000000; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 6 == 0) {
            dp[i] = min(dp[i], min(dp[i / 3] + 1, dp[i / 2] + 1));
        } else if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        } else if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}