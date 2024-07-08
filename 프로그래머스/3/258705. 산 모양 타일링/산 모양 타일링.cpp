#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 3;
    int prevTriangleCount = 1;
    int prevReverseRhombusCount = 1;
    int prevTopRhombusCount = 0;
    bool isTopPrev = false;
    if (tops[0] == 1) {
        prevTopRhombusCount = 1;
        answer += prevTopRhombusCount;
        isTopPrev = true;
    }
    for (int i = 1; i < n; i++) {
        int prevTotal = answer;
        if (tops[i] == 1) {
            answer = prevTotal * 3 + prevTriangleCount + prevReverseRhombusCount;
        } else {
            answer = prevTotal * 2 + prevTriangleCount + prevReverseRhombusCount;
        }

        if (isTopPrev) {
            answer += prevTopRhombusCount;
            prevReverseRhombusCount = (prevTriangleCount + prevReverseRhombusCount + prevTopRhombusCount) % 10007;
        } else {
            prevReverseRhombusCount = (prevTriangleCount + prevReverseRhombusCount) % 10007;
        }

        if (tops[i] == 1) {
            isTopPrev = true;
        } else {
            isTopPrev = false;
        }
        prevTriangleCount = prevTotal % 10007;
        prevTopRhombusCount = prevTotal % 10007;
        answer %= 10007;
    }
    return answer;
}