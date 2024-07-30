#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int maxDiff = 0;

vector<int> getSmallerVector(vector<int>& a, vector<int>& b) {
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] > b[i]) {
            return a;
        } else if (a[i] < b[i]) {
            return b;
        }
    }
    return a;
}

int calculateDiff(vector<int>& lionInfo, vector<int>& apeachInfo) {
    int lionPoint = 0;
    int apeachPoint = 0;
    for (int i = 0; i < lionInfo.size(); i++) {
        if (lionInfo[i] == 0 && apeachInfo[i] == 0) {
            continue;
        }
        
        if (lionInfo[i] > apeachInfo[i]) {
            lionPoint += (10 - i);
        } else {
            apeachPoint += (10 - i);
        } 
    }
    return lionPoint - apeachPoint;
}

void backtrack(int remain, int depth, vector<int> lionInfo, vector<int>& apeachInfo) {
    if (remain == 0) {
        int diff = calculateDiff(lionInfo, apeachInfo);
        if (diff > maxDiff) {
            answer = lionInfo;
            maxDiff = diff;
        } else if (diff == maxDiff) {
            answer = getSmallerVector(answer, lionInfo);
        }
        return;
    }
    
    if (depth > 10) {
        return;
    }
    
    for (int i = 0; i <= remain; i++) {
        lionInfo[depth] = i;
        backtrack(remain - i, depth + 1, lionInfo, apeachInfo);
    }
}

vector<int> solution(int n, vector<int> info) {
    int depth = 0;
    vector<int> lionInfo(info.size(), 0);
    for (int i = 0; i <= n; i++) {
        lionInfo[depth] = i;
        backtrack(n - i, depth + 1, lionInfo, info);
    }
    if (maxDiff > 0) {
        return answer;
    }
    return vector<int>(1, -1);
}