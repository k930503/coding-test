#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> child;
vector<child> binaryTree;

void preorderTraversal(int node) {
    cout << (char)(node + 'A');
    if (binaryTree[node].first != -1) {
        preorderTraversal(binaryTree[node].first);
    }

    if (binaryTree[node].second != -1) {
        preorderTraversal(binaryTree[node].second);
    }
}

void inorderTraversal(int node) {
    if (binaryTree[node].first != -1) {
        inorderTraversal(binaryTree[node].first);
    }

    cout << (char)(node + 'A');

    if (binaryTree[node].second != -1) {
        inorderTraversal(binaryTree[node].second);
    }
}

void postOrderTraversal(int node) {
    if (binaryTree[node].first != -1) {
        postOrderTraversal(binaryTree[node].first);
    }

    if (binaryTree[node].second != -1) {
        postOrderTraversal(binaryTree[node].second);
    }

    cout << (char)(node + 'A');
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;
    cin >> n;
    binaryTree.assign(n, {-1, -1});
    for (int i = 0; i < n; i++) {
        char parent, lchild, rchild;
        cin >> parent >> lchild >> rchild;
        int p = parent - 'A';
        if (lchild != '.') {
            int l = lchild - 'A';
            binaryTree[p].first = l;
        }
        if (rchild != '.') {
            int r = rchild - 'A';
            binaryTree[p].second = r;
        }
    }

    preorderTraversal(0);
    cout << '\n';
    inorderTraversal(0);
    cout << '\n';
    postOrderTraversal(0);
    return 0;
}