#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cnt = 0;

    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1, 0);
    int start, end;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    start = 1;
    end = N;

//    if (N == 1 || M == 1 || v[end] + v[end - 1] < M) {
//        return cnt;
//    }

    while (start < end) {
        if (M > v[start] + v[end]) {
            start++;
        } else if (M < v[start] + v[end]) {
            end--;
        } else {
            cnt++;
            end--;
            start++;
        }
    }
    cout << cnt;
    return 0;
}
