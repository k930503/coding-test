#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    long long min, max;
    cin >> min >> max;
    vector<bool> eratos(max - min + 1, false);

    // 에라토스테네스의 체
    for (long long i = 2; i * i <= max; i++) {
        long long pow = i * i;
        long long startIndex = min / pow;
        if (min % pow != 0) {
            startIndex++;
        }
        for (long long j = startIndex; j * pow <= max; j++) {
            eratos[j * pow - min] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < eratos.size(); i++) {
        if (!eratos[i]) {
            count++;
        }
    }
    cout << count;
    return 0;
}