#include <string>
#include <vector>

using namespace std;

int countZero = 0;
int countOne = 0;

void process(int startX, int startY, int size, vector<vector<int>>& arr) {
    bool foundZero = false;
    bool foundOne = false;
    for (int i = startX; i < startX + size; i++) {
        for (int j = startY; j < startY + size; j++) {
            if (arr[i][j] == 0) {
                foundZero = true;
            } else {
                foundOne = true;
            }
            if (foundZero && foundOne) {
                break;
            }
        }
    }
    if (foundZero && !foundOne) {
        countZero++;
    } else if (!foundZero && foundOne) {
        countOne++;
    } else {
        int half = size / 2;
        process(startX, startY, half, arr);
        process(startX, startY + half, half, arr);
        process(startX + half, startY, half, arr);
        process(startX + half, startY + half, half, arr);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    process(0, 0, arr.size(), arr);
    answer.push_back(countZero);
    answer.push_back(countOne);
    return answer;
}