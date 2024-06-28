#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

void unionParent(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA != parentB) {
        if (parent[parentA] > parent[parentB]) {
            parent[parentA] = parentB;
        } else {
            parent[parentB] = parentA;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int temp;
            cin >> temp;
            if (i >= j) {
                continue;
            }
            if (temp == 1) {
                unionParent(i, j);
            }
        }
    }

    int temp;
    cin >> temp;
    int set = findParent(temp);
    for (int i = 1; i < m; i++) {
        cin >> temp;
        if (set != findParent(temp)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}