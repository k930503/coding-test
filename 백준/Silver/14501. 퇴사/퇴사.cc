#include <iostream>
#include <vector>
using namespace std;

struct task {
    int t;
    int p;
};

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    vector<task> a(n + 1);
    vector<int> dp(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].p;
    }

    for (int i = n; i >= 1; i--) {
        dp[i] = dp[i + 1];
        if (a[i].t + i - 1 > n) {
            continue;
        }
        if (a[i].p + dp[i + a[i].t] > dp[i + 1] ) {
            dp[i] = a[i].p + dp[i + a[i].t];
        }
    }
    cout << dp[1];


    return 0;
}