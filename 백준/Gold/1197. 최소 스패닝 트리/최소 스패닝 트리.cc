#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edgeList;
vector<int> parent;
int v, e;
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
    for (int i = 0; i < e; i++) {
        int a = get<1>(edgeList[i]);
        int b = get<2>(edgeList[i]);
        int weight = get<0>(edgeList[i]);
        if (!isSameParent(a, b)) {
            unionParent(a, b);
            answer += weight;
            count++;
        }
        if (count == v - 1) {
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> v >> e;
    edgeList.resize(e);
    parent.resize(v + 1);
    for (int i = 1; i <= v; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList[i] = make_tuple(c, a, b);
    }
    kruskal();
    cout << answer;
    return 0;
}