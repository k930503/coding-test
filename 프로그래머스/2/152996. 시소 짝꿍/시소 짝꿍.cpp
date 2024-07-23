#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(), weights.end());
    for (int i = 0; i < weights.size() - 1; i++) {
        for (int j = i + 1; j < weights.size(); j++) {
            if (weights[i] * 2 < weights[j]) {
                break;
            }
            if (weights[i] == weights[j] 
                || weights[i] * 2 == weights[j] 
                || weights[i] * 3 == weights[j] * 2 
                || weights[i] * 4 == weights[j] * 3) {
                answer++;
            }
        }
    }
    return answer;
}