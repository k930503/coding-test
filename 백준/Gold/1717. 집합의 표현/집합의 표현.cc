#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int node) {
    if (node == parent[node]) {
        return node;
    }
    return parent[node] = find(parent[node]);
}

void unionParent(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    if (parentA > parentB) {
        parent[parentA] = parentB;
    } else {
        parent[parentB] = parentA;
    }
}

bool checkSame(int a, int b) {
    int parentA = find(a);
    int parentB = find(b);
    return parentA == parentB;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int instructor, a, b;
        cin >> instructor >> a >> b;
        if (instructor == 0) {
            unionParent(a, b);
        } else {
            if (checkSame(a, b)) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}