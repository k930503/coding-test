#include <iostream>
#include <vector>
using namespace std;

vector<long long> permutationCases;
vector<int> permutation;
vector<bool> visited;
int n;
long long k;

void setPermutationByOrder() {
    cin >> k;
    for (int i = 1; i <= n; i++) {
        int count = 1;
        for (int j = 1; j <= n; j++) {
            if (visited[j]) {
                continue;
            }
            if (k <= count * permutationCases[n - i]) {
                permutation[i] = j;
                k -= ((count - 1) * permutationCases[n - i]);
                visited[j] = true;
                break;
            }
            count++;
        }
    }
}

void getOrderByPermutation() {
    for (int i = 1; i <= n; i++) {
        cin >> permutation[i];
    }
    k = 1;
    for (int i = 1; i <= n; i++) {
        int count = 1;
        for (int j = 1; j <= n; j++) {
            if (visited[j]) {
                continue;
            }
            if (permutation[i] == j) {
                k += ((count - 1) * permutationCases[n - i]);
                visited[j] = true;
                break;
            }
            count++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    int problem;
    cin >> problem;
    permutationCases.resize(n + 1);
    permutation.resize(n + 1);
    visited.assign(n + 1, false);
    permutationCases[0] = 1;
    for (int i = 1; i <= n; i++) {
        permutationCases[i] = i * permutationCases[i - 1];
    }

    if (problem == 1) {
        setPermutationByOrder();
        for (int i = 1; i <= n; i++) {
            cout << permutation[i] << ' ';
        }
    } else {
        getOrderByPermutation();
        cout << k;
    }
    return 0;
}