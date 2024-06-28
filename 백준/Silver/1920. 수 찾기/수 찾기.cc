#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        int midIdx = (n - 1) / 2;
        int midVal = a[midIdx];
        int start = 0;
        int end = n - 1;
        bool found = false;
        while (start <= end) {
            if (target < midVal) {
                end = midIdx - 1;
            } else if (target > midVal) {
                start = midIdx + 1;
            } else {
                found = true;
                break;
            }
            midIdx = (start + end) / 2;
            midVal = a[midIdx];
        }
        if (found) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}