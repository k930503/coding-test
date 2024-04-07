#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    long long start = 1;
    long long end = k;
    long long mid = (start + end) / 2;
    long long answer = 0;
    while (start <= end) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            long long temp = mid / i;
            if (temp > n) {
                sum += n;
            } else {
                sum += temp;
            }
        }
        if (sum >= k) {
            end = mid - 1;
            answer = mid;
        } else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    cout << answer;
    return 0;
}