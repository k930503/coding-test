#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    long long a, b;
    cin >> a >> b;
    while (b % a != 0) {
        long long temp = a;
        a = b % a;
        b = temp;
    }
    for (int i = 0; i < a; i++) {
        cout << 1;
    }
    return 0;
}