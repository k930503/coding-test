#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        int n, m;
        cin >> n >> m;
        int r = 1;
        int answer = 1;
        for (int j = m; j > m - n; j--) {
            answer *= j;
            answer /= r++;
        }
        cout << answer << '\n';
    }
    return 0;
}