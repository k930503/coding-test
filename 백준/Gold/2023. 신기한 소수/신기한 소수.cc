#include <iostream>

using namespace std;

int n;

bool isPrimeNumber(int num){
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void bt(int num, int digit) {
    for (int i = 1; i < 10; i += 2) {
        int target = num + i;
        if (isPrimeNumber(target)) {
            if (digit == n) {
                cout << target << '\n';
            } else if (digit < n) {
                bt(target * 10, digit + 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    if (n == 1) {
        cout << 2 << '\n';
        cout << 3 << '\n';
        cout << 5 << '\n';
        cout << 7 << '\n';
        return 0;
    }

    bt(20, 2);
    bt(30, 2);
    bt(50, 2);
    bt(70, 2);

    return 0;
}