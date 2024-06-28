#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n + 1, 0);
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = (i - 1) * (a[i - 2] + a[i - 1]) % 1000000000;
    }
    cout << a[n];
    return 0;
}