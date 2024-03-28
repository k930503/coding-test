#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    while (n > 0) {
        v.push_back(n % 10);
        n = n / 10;
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[maxIdx] < v[j]) {
                maxIdx = j;
            }
        }
        swap(v[i], v[maxIdx]);
    }

    int answer = 0;
    for (int i = 0; i < v.size(); i++) {
        answer += v[i] * int(pow(10, v.size() - i - 1));
    }
    cout << answer;
    return 0;
}
