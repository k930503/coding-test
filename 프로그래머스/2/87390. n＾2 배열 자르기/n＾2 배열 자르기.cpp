#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int curX = left / n;
    int curY = left % n;
    int endX = right / n;
    int endY = right % n;
    
    while (curX != endX || curY != endY) {
        answer.push_back(max(curX + 1, curY + 1));
        if ((curY + 1) % n == 0) {
            curX++;
            curY = 0;
        } else {
            curY++;
        }
    }
    answer.push_back(max(endX + 1, endY + 1));
    
    return answer;
}



