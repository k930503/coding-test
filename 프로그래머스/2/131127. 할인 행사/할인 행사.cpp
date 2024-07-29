#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool check(vector<string>& want, vector<int>& number, unordered_map<string, int>& current) {
    for (int i = 0; i < want.size(); i++) {
        if (current[want[i]] != number[i]) {
            return false;
        }
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> current;
    
    for (int i = 0; i < 10; i++) {
        current[discount[i]]++;
    }
    
    if (check(want, number, current)) {
        answer++;
    }
    
    for (int i = 0; i < discount.size() - 10; i++) {
        current[discount[i]]--;
        current[discount[i + 10]]++;
        if (check(want, number, current)) {
            answer++;
        }
    }
    return answer;
}