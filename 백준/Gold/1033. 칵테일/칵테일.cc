#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<vector<tuple<int, int, int>>> adjacentList;
vector<bool> visited;
vector<long long> estimates;
int n;
long long lcm = 1;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adjacentList[node].size(); i++) {
        tuple<int, int, int> next = adjacentList[node][i];
        if (!visited[get<0>(next)]) {
            estimates[get<0>(next)] = estimates[node] * get<2>(next) / get<1>(next);
            dfs(get<0>(next));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    cin >> n;
    adjacentList.resize(n);
    visited.assign(n, false);
    estimates.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        adjacentList[a].emplace_back(b, p, q);
        adjacentList[b].emplace_back(a, q, p);
        lcm *= p * q / (gcd(p, q));
    }

    estimates[0] = lcm;
    dfs(0);
    long long gcdVal = estimates[0];

    for (int i = 1; i < n; i++) {
        gcdVal = gcd(gcdVal, estimates[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << estimates[i] / gcdVal << ' ';
    }
    return 0;
}