#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int answer = 0;
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        answer += sum;
    }
    cout << answer;
    return 0;
}