#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int totalZeroCount = 0;
    int loopCount = 0;
    while (s != "1") {
        int zeroCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                zeroCount++;
            }
        }
        int temp = s.length() - zeroCount;
        s = "";
        while (temp > 0) {
            if (temp % 2 == 1) {
                s += '1';
            } else {
                s += '0';
            }
            temp /= 2;
        }
        totalZeroCount += zeroCount;
        loopCount++;
    }
    answer.push_back(loopCount);
    answer.push_back(totalZeroCount);
    return answer;
}