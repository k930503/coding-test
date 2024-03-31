#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> result(n, 0);
    vector<int> a(n, 0);
    stack<int> stack;

    cin >> a[0];
    stack.push(0);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        while (!stack.empty() && a[stack.top()] < a[i]) {
            result[stack.top()] = a[i];
            stack.pop();
        }
        stack.push(i);
    }

    while (!stack.empty()) {
        result[stack.top()] = -1;
        stack.pop();
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
