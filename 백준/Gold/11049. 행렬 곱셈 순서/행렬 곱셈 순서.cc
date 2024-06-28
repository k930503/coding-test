#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef pair<int, int> matrix;

int n;
vector<matrix> a;
vector<vector<int>> dp;

int execute(int s, int e) {
    if (dp[s][e] != -1) {
        return dp[s][e];
    }

    int result = INT_MAX;
    if (s == e) {
        result = 0;
    } else if (s + 1 == e) {
        result = a[s].first * a[s].second * a[e].second;
    } else {
        for (int i = s; i < e; i++) {
            result = min(result, a[s].first * a[i].second * a[e].second + execute(s, i) + execute(i + 1, e));
        }
    }
    return dp[s][e] = result;
}

int main() {
    cin >> n;
    a.resize(n);
    dp.assign(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        matrix m;
        cin >> m.first >> m.second;
        a[i] = m;
    }

    cout << execute(0, n - 1);
    return 0;
}