#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int a[15][15] = {0,};
    for (int i = 1; i <= 14; i++) {
        a[0][i] = i;
    }
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }

    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int testK, testN;
        cin >> testK >> testN;
        cout << a[testK][testN] << '\n';
    }
    return 0;
}