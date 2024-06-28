#include <iostream>
#include <vector>
#include <tuple>
#include <cctype>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> edge;

vector<edge> edgeList;
int n;
vector<int> parent;
int answer = 0;

int findParent(int vertex) {
    if (parent[vertex] == vertex) {
        return vertex;
    } else {
        return parent[vertex] = findParent(parent[vertex]);
    }
}

void unionParent(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA != parentB) {
        if (parentA < parentB) {
            parent[parentB] = parentA;
        } else {
            parent[parentA] = parentB;
        }
    }
}

bool isSameParent(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    if (parentA == parentB) {
        return true;
    }
    return false;
}

void kruskal() {
    sort(edgeList.begin(), edgeList.end());
    int count = 0;
    for (edge e : edgeList) {
        int a = get<1>(e);
        int b = get<2>(e);
        int weight = get<0>(e);
        if (!isSameParent(a, b)) {
            unionParent(a, b);
            count++;
        } else {
            answer += weight;
        }
    }
    if (count != n - 1) {
        answer = -1;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char input;
            cin >> input;
            if (input == '0') {
                continue;
            } else if (isupper(input)) {
                edgeList.emplace_back((int)input - 38, i, j);
            } else {
                edgeList.emplace_back((int)input - 96, i, j);
            }
        }
    }
    kruskal();
    cout << answer;
    return 0;
}