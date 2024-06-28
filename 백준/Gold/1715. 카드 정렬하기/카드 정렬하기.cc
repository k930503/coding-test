#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<>> myqueue;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        myqueue.push(input);
    }

    int answer = 0;
    while (myqueue.size() > 1) {
            int val1 = myqueue.top();
            myqueue.pop();
            int val2 = myqueue.top();
            myqueue.pop();
            int temp = val1 + val2;
            myqueue.push(temp);
            answer += temp;
    }
    cout << answer;
    return 0;
}