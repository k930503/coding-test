#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int val) {
    if (val == 1) {
        return false;
    }
    for (int i = 2; i * i <= val; i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPalindrom(int val) {
    string str = to_string(val);
    for (int i = 0; i < ceil((int)str.length() / 2.0); i++) {
        if (str[i] != str[str.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;

    while (!isPalindrom(n) || !isPrime(n)) {
        n++;
    }
    cout << n;
    return 0;
}