#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> lectures(n, 0);
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        cin >> lectures[i];
        if (start < lectures[i]) {
            start = lectures[i];
        }
        end += lectures[i];
    }

    while (start <= end) {
        int sum = 0;
        int count = 1;
        int mid = (start + end) / 2;
        bool completed = true;
        for (int i = 0; i < lectures.size(); i++) {
            if (sum + lectures[i] <= mid) {
                sum += lectures[i];
            } else {
                if (count < m) {
                    sum = lectures[i];
                    count++;
                } else {
                    start = mid + 1;
                    completed = false;
                    break;
                }
            }
        }
        if (completed) {
            end = mid - 1;
        }
    }
    cout << start;
    return 0;
}