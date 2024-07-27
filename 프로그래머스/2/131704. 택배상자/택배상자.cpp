#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int current = 1;
    for (int i = 0; i < order.size(); i++) {
        while (order[i] > current) {
            s.push(current++);
        }
        if (order[i] == current) {
            answer++;
            current++;
        } else if (order[i] == s.top()) {
            answer++;
            s.pop();
        } else {
            break;
        }
    }
    return answer;
}