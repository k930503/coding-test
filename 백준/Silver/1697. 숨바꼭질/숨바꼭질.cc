#include <iostream>
#include <queue>

using namespace std;

int bfs(int n, int k) {
    queue<int> q;
    q.push(n);
    bool visited[1000001] = { false, };
    int count = 0;
    int second = 0;
    int curDepthSize = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == k) {
            break;
        }
        count++;
        int next = cur - 1;
        if (next > -1 && next < 100001 && !visited[next]) {
            q.push(next);
            visited[next] = true;
        }

        next = cur + 1;
        if (next > -1 && next < 100001 && !visited[next]) {
            q.push(next);
            visited[next] = true;
        }
        next = cur * 2;
        if (next > -1 && next < 100001 && !visited[next]) {
            q.push(next);
            visited[next] = true;
        }
        if (count == curDepthSize) {
            second++;
            count = 0;
            curDepthSize = (int)q.size();
        }
    }
    return second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
    return 0;
}