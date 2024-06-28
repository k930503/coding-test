#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer = 0;
    int index = n - 1;
    while (k > 0) {
        if (k >= a[index]) {
            answer += k / a[index];
            k %= a[index];
        }
        index--;
    }

    cout << answer;
    return 0;
}