#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a;
int n;

void floydwarshall() {
    for (int k = 0; k < n; k++) {
        for (int src = 0; src < n; src++) {
            for (int dst = 0; dst < n; dst++) {
                if (a[src][k] == 1 && a[k][dst] == 1) {
                    a[src][dst] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    a.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    floydwarshall();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}