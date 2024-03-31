#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cout << v[k - 1];
    return 0;
}
