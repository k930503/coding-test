#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    long long a, b;
    cin >> a >> b;
    int end = (int)sqrt(b);
    vector<bool> eratos(end + 1, false);
    eratos[0] = eratos[1] = true;
    for (int i = 2; i * i <= end; i++) {
        for (int j = 2; j * i <= end; j++) {
            eratos[j * i] = true;
        }
    }

    int answer = 0;
    for (int i = 2; i <= end; i++) {
        if (eratos[i]) {
            continue;
        }
        long long temp = i;
        while ((double)i <= (double)b / (double)temp) {
            if ((double)i >= (double)a / (double)temp) {
                answer++;
            }
            temp *= i;
        }
    }
    cout << answer;
    return 0;
}