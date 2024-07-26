#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;
    for (int t: tangerine) {
        if (m.find(t) != m.end()) {
            m[t]++;
        } else {
            m[t] = 1;
        }
    }
    
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto it: m) {
        pq.push(it.second);
    }
    
    int amount = 0;
    while (amount < k) {
        amount += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}