#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int small = a;
        int big = b;
        // 유클리드 호제법
        while (big % small != 0) {
            int temp = big % small;
            big = small;
            small = temp;
        }
        cout << small * (a / small) * (b / small) << '\n';
    }
    return 0;
}