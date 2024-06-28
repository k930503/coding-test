#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adjacencyList;
int rmNode;
int answer = 0;
void dfs (int node) {
    if (node == rmNode) {
        return;
    }

    if (adjacencyList[node].empty()) {
        answer++;
    } else {
        for (int next : adjacencyList[node]) {
            if (next == rmNode && adjacencyList[node].size() == 1) {
                answer++;
            } else {
                dfs(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    adjacencyList.assign(n, vector<int>(0));
    int root = -1;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if (input == -1) {
            root = i;
        } else {
            adjacencyList[input].push_back(i);
        }
    }
    cin >> rmNode;
    dfs(root);
    cout << answer;
    return 0;
}