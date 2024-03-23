#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int naturalNum = 1;
    stack<int> stack;
    vector<char> result;
    int n;
    cin >> n;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num >= naturalNum) {
            while (num >= naturalNum) {
                stack.push(naturalNum++);
                result.push_back('+');

            }
            stack.pop();
            result.push_back('-');
        } else {
            if (num == stack.top()) {
                stack.pop();
                result.push_back('-');
            } else {
                cout << "NO";
                return 0;
            }
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }
    return 0;
}

