#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static vector < vector <int> > A;
static vector<bool> visited;
static bool arrive;
void DFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Start;
    arrive = false;
    cin >> N >> M >> Start;
    A.resize(N+1);

    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    // �湮�� �� �ִ� ��尡 ���� ���� ��쿡�� ��ȣ�� ���� ���� ���� �湮 �ϱ� ���� ����
    for (int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
    }

    visited = vector<bool>(N+1, false); 
    DFS(Start);
    cout << "\n";
    fill(visited.begin(), visited.end(), false); // �湮 �迭 �ʱ�ȭ
    BFS(Start);
    cout << "\n";
}

void DFS(int node) {  // DFS����
    cout << node << " ";
    visited[node] = true;
    for (int i : A[node]) {
        if (!visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int node) {  // BFS����
    queue<int> myqueue;
    myqueue.push(node);
    visited[node] = true;

    while (!myqueue.empty()) {
        int now_node = myqueue.front();
        myqueue.pop();
        cout << now_node << " ";
        for (int i : A[now_node]) {
            if (!visited[i]) {
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}