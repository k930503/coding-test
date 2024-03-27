#include <iostream>
#include <queue>

using namespace std;

int main() {

    struct compare {
        bool operator()(int a, int b) {
            int absA = abs(a);
            int absB = abs(b);
            if (absA == absB) {
                return a > b;
            }
            return absA > absB;
        }
    };

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, compare> pq;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << '0' << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(num);
        }
    }
    return 0;
}
