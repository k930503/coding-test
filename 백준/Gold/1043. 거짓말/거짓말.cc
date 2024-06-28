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
        parent[parentB] = parentA;
    }
}

bool checkSame(int a, int b) {
    int parentA = findParent(a);
    int parentB = findParent(b);
    return parentA == parentB;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> partyFirstPerson(m, 0);
    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int knowNum;
    cin >> knowNum;
    vector<int> know(knowNum);
    for (int i = 0; i < knowNum; i++) {
        int knowSomeone;
        cin >> knowSomeone;
        know[i] = knowSomeone;
    }

    for (int i = 0; i < m; i++) {
        int count;
        cin >> count;
        int firstPerson;
        cin >> firstPerson;
        partyFirstPerson[i] = firstPerson;
        for (int j = 0; j < count - 1; j++) {
            int person;
            cin >> person;
            unionParent(firstPerson, person);
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++) {
        bool isSame = false;
        for (int j = 0; j < knowNum; j++) {
            if (checkSame(partyFirstPerson[i], know[j])) {
                isSame = true;
                break;
            }
        }
        if (!isSame) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}