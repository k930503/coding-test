#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> v[10001];
bool visit[10001];
int cnt = 0;
int mm = 0;
int result[10001];

void dfs(int n) {
    cnt++;

    for (int i = 0; i < v[n].size(); i++) {
        int nn = v[n][i];

        if (visit[nn]) continue;

        visit[nn] = true;
        dfs(nn);
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        memset(visit, false, sizeof(visit));

        cnt = 0;

        visit[i] = true;
        dfs(i);

        result[i] = cnt;
        mm = max(mm, cnt);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == mm) {
            cout << i << " ";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    solution();

    return 0;
}