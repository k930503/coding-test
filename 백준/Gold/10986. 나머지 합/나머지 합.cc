#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    long sum[1000001] = {0,};
    long mod[1000] = {0,};
    long count = 0;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum[i] = sum[i - 1] + num;
        int temp = sum[i] % M;
        if (temp == 0) {
            count++;
        }
        mod[temp]++;
    }

    for (int i = 0; i < M; i++) {
        if (mod[i] > 1) {
            count += mod[i] * (mod[i] - 1) / 2;
        }
    }

    cout << count;
    return 0;
}
