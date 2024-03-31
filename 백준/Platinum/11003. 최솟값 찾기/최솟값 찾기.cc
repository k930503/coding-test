#include <iostream>
#include <deque>

using namespace std;
typedef pair<int, int> Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;
    deque<Node> deque;

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        // 값이 들어올 때마다 정렬하지 않고
        // 현재 수보다 큰 값을 덱에서 제거하여 시간 복잡도를 줄임
        while (!deque.empty() && deque.back().second > now) {
            deque.pop_back();
        }
        deque.push_back(Node(i, now));
        // 범위에서 벗어난 값은 덱에서 제거
        if (deque.front().first <= i - L) {
            deque.pop_front();
        }
        cout << deque.front().second << ' ';
    }
    return 0;
}
