#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a;
    a.assign(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++) {
        a[i][0] = 1;
        a[i][1] = i;
        a[i][i] = 1;
    }
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < n; j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    cout << a[n][k];
    return 0;
}