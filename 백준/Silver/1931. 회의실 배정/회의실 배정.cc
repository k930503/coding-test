#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> meeting;

struct cmp {
    bool operator()(meeting a, meeting b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<meeting, vector<meeting>, cmp> pq;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        pq.emplace(first,second);
    }

    int possibleTime = 0;
    int answer = 0;
    while (!pq.empty()) {
        meeting m = pq.top();
        if (m.first >= possibleTime) {
            possibleTime = m.second;
            answer++;
        }
        pq.pop();
    }
    cout << answer;
    return 0;
}