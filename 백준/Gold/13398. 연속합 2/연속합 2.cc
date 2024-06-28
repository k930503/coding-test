#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> left(n);
    vector<int> right(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        cout << a[0];
        return 0;
    }

    left[0] = a[0];
    for (int i = 1; i < n; i++) {
        left[i] = max(a[i], left[i - 1] + a[i]);
    }
    right[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(a[i], right[i + 1] + a[i]);
    }

    int answer = max(right[0], left[n - 1]);
    for (int i = 1; i < n - 1; i++) {
        answer = max(answer, max(a[i], max(a[i] + left[i - 1] + right[i + 1], left[i - 1] + right[i + 1])));
    }
    cout << answer;
    return 0;
}