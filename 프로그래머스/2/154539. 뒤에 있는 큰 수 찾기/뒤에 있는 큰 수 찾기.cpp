#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size());
    stack<int> s;
    s.push(0);
    for (int i = 1; i < numbers.size(); i++) {
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        answer[s.top()] = -1;
        s.pop();
    }
    
    return answer;
}