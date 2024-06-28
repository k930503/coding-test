#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    long long n;
    cin >> n;
    long long answer = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            answer = answer - answer / i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }

    if (n > 1) {
        answer = answer - answer / n;
    }
    cout << answer;
    return 0;
}