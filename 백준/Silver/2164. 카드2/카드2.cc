#include <iostream>
#include <queue>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    queue<int> queue;

    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }

    bool flag = true;
    while (queue.size() > 1) {
        if (flag) {
            queue.pop();
        } else {
            queue.push(queue.front());
            queue.pop();
        }
        flag = !flag;
    }

    cout << queue.front();
    return 0;
}
