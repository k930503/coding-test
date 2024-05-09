#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

vector<long long> tree;

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
        tree[i / 2] = tree[i / 2] % MOD * tree[i] % MOD;
    }
}

void changeNode(int index, long long val) {
    tree[index] = val;
    while (index > 1) {
        if (index % 2 == 0) {
            tree[index / 2] = tree[index] % MOD * tree[index + 1] % MOD;
        } else {
            tree[index / 2] = tree[index] % MOD * tree[index - 1] % MOD;
        }
        index /= 2;
    }
}

long long getPartMul(int start, int end) {
    long long ret = 1;
    while (start <= end) {
        if (start % 2 == 1) {
            ret = ret * tree[start] % MOD;
        }
        if (end % 2 == 0) {
            ret = ret * tree[end] % MOD;
        }
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    int treeArraySize = getTreeArraySize(n);
    tree.assign(treeArraySize, 1);
    int leafStartIdx = treeArraySize / 2;
    setTree(n, leafStartIdx);
    for (int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int treeIdx = leafStartIdx + b - 1;
        if (a == 1) {
            changeNode(treeIdx, c);
        } else {
            int end = leafStartIdx + c - 1;
            cout << getPartMul(treeIdx, end) % MOD << '\n';
        }
    }
    return 0;
}