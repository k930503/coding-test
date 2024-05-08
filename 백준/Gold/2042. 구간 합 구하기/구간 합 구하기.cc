#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;

long long getTreeSize(long long n) {
    long long ret = 2;
    while (ret < n) {
        ret *= 2;
    }
    return ret * 2;
}

void setTree(long long n, long long leafStartIdx) {
    for (long long i = leafStartIdx; i < leafStartIdx + n; i++) {
        cin >> tree[i];
    }
    for (long long i = leafStartIdx + n - 1; i > 1; i--) {
        tree[i / 2] += tree[i];
    }
}

void changeNode(long long nodeIdx, long long val) {
    long long diff = val - tree[nodeIdx];
    while (nodeIdx > 0) {
        tree[nodeIdx] += diff;
        nodeIdx /= 2;
    }
}

long long getPartSum(long long start, long long end) {
    long long sum = 0;
    while (start <= end) {
        if (start % 2 == 1) {
            sum += tree[start];
        }
        if (end % 2 == 0) {
            sum += tree[end];
        }
        start = (start + 1) / 2;
        end = (end - 1) / 2;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    long long n, m, k;
    cin >> n >> m >> k;
    long long treeArraySize = getTreeSize(n);
    tree.resize(treeArraySize);
    long long leafStartIdx = treeArraySize / 2;
    setTree(n, leafStartIdx);
    for (long long i = 0; i < m + k; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long treeIdx = leafStartIdx + b - 1;
        if (a == 1) {
            changeNode(treeIdx, c);
        } else {
            long long end = leafStartIdx + c - 1;
            cout << getPartSum(treeIdx, end) << '\n';
        }
    }
    return 0;
}