#include <iostream>

using namespace std;

int calculateSequenceSum(int start, int n) {
    return n * (2 * start + n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int start = 1;
    int end = 1;
    int cnt = 0;

    cin >> N;

    while (start <= N) {
        int temp = calculateSequenceSum(start, end - start + 1);
        if (temp == N) {
            cnt++;
            if (end == N) {
                break;
            }
            start++;
            end++;
        } else if (temp > N) {
            start++;
        } else {
            if (end == N) {
                break;
            }
            end++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
