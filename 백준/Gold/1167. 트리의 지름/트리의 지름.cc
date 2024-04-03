#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a;
vector<bool> visited;
pair<int, int> maximum;

void dfs(int num, int dist) {
    visited[num] = true;
    if (maximum.second < dist) {
        maximum.first = num;
        maximum.second = dist;
    }
    for (int i = 0; i < a[num].size(); i += 2) {
        if (!visited[a[num][i]]) {
            dfs(a[num][i], dist + a[num][i + 1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v;
    cin >> v;

    a.assign(v + 1, vector<int>(0, 0));
    visited.assign(v + 1, false);

    for (int i = 0; i < v; i++) {
        int vertexNum;
        cin >> vertexNum;
        for (int j = 0; true; j++) {
            int input;
            cin >> input;
            if (input == -1) {
                break;
            }
            a[vertexNum].push_back(input);
        }
    }

    maximum = make_pair(1, 0);

    dfs(maximum.first, maximum.second);

    fill(visited.begin(), visited.end(), false);

    maximum.second = 0;

    dfs(maximum.first, maximum.second);

    cout << maximum.second;
    return 0;
}