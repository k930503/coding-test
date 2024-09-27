#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
        vector<char> v;
        bool isCorrect = true;
        for (int j = i; j < s.length() + i; j++) {
            int index = j % s.length();
            if (s[index] == '[' || s[index] == '{' || s[index] == '(') {
                v.push_back(s[index]);
            } else if (!v.empty() && ((s[index] == ']' && v.back() == '[') || (s[index] == '}' && v.back() == '{') || (s[index] == ')' && v.back() == '('))) {
                v.pop_back();
            } else {
                isCorrect = false;
                break;
            }
        }
        if (isCorrect && v.empty()) {
            answer++;
        }
    }
    return answer;
}