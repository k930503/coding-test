#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n, 0);
    int sum = 0;
    int negativeNumAndZeroCnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        if (v[i] <= 0) {
            negativeNumAndZeroCnt++;
        }
    }

    sort(v.begin(), v.end());

    int answer = sum;
    for (int i = 0; i < negativeNumAndZeroCnt - 1; i += 2) {
        answer -= v[i] + v[i + 1];
        answer += v[i] * v[i + 1];
    }

    for (int i = (int)v.size() - 1; i > negativeNumAndZeroCnt && v[i] > 1 && v[i - 1] > 1; i -= 2) {
        answer -= v[i] + v[i - 1];
        answer += v[i] * v[i - 1];
    }

    if (answer < sum) {
        answer = sum;
    }
    cout << answer;
    return 0;
}