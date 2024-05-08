#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

int getTreeArraySize(int n) {
    int ret = 1;
    while (ret < n) {
        ret *= 2;
    }
    return ret * 2;
}

void setTree(int n, int leafStartIdx) {
    for (int i = leafStartIdx; i < leafStartIdx + n; i++) {
        cin >> tree[i];
    }
    for (int i = leafStartIdx + n - 1; i > 1; i--) {
        tree[i / 2] = min(tree[i / 2], tree[i]);
    }
}

int getPartMin(int start, int end) {
    int minimum = 1000000000;
    while (start <= end) {
        if (start % 2 == 1) {
            minimum = min(minimum, tree[start]);
        }
        if (end % 2 == 0) {
            minimum = min(minimum, tree[end]);
        }
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return minimum;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int treeArraySize = getTreeArraySize(n);
    tree.assign(treeArraySize, 1000000000);
    int leafStartIdx = treeArraySize / 2;
    setTree(n, leafStartIdx);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int start = leafStartIdx + a - 1;
        int end = leafStartIdx + b - 1;
        cout << getPartMin(start, end) << '\n';
    }
    return 0;
}