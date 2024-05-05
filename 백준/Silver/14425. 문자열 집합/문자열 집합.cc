#include <iostream>
using namespace std;

class Node {
    Node* next[26]{nullptr};
    bool isEnd = false;
public:
    void insert(const char* c) {
        if (*c == '\0') {
            isEnd = true;
            return;
        }

        int nextIndex = *c - 'a';
        if (next[nextIndex] == nullptr) {
            next[nextIndex] = new Node();
        }
        next[nextIndex]->insert(c + 1);
    }

    bool find(char* c) {
        if (*c == '\0' && isEnd) {
            return true;
        }
        int nextIndex = *c - 'a';
        if (next[nextIndex] == nullptr) {
            return false;
        } else {
            return next[nextIndex]->find(c + 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    Node root;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char text[501];
        cin >> text;
        root.insert(text);
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        char text[501];
        cin >> text;
        if (root.find(text)) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}