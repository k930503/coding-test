//
// Created by 김영민 on 3/31/24.
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// https://katteniiki.tistory.com/23

// 에라토스테네스의 체(소수 구하기)
int main() {
    int m, n;
    cin >> m >> n;

    vector<bool> v(n + 1, false);

    v[0] = v[1] = true;

    for (int i = 2; i * i <= n; i++) {
        if (v[i]) {
            continue;
        }
        for (int j = 2; j * i <= n; j++) {
            v[j * i] = true;
        }
    }

    for (int i = m; i <= n; i++) {
        if (!v[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}