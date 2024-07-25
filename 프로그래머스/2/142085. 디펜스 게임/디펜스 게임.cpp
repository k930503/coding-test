#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    int remainCount = n;
    for (int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);
        if (remainCount >= enemy[i]) {
            remainCount -= enemy[i];
        } else if (k > 0) {
            int prevMax = pq.top();
            pq.pop();
            remainCount += prevMax;
            remainCount -= enemy[i];
            k--;
        } else {
            answer = i;
            break;
        }
    }
    if (answer == 0) {
        answer = enemy.size();
    }
    return answer;
}