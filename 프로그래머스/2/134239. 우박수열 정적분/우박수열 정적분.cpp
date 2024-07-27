#include <string>
#include <vector>

using namespace std;

double getDefiniteIntegral(int x1, int x2, vector<int>& hails) {
    double ret = 0;
    for (int i = x1; i < x2; i++) {
        ret += (double)(hails[i] + hails[i + 1]) / 2;
    }
    return ret;
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> hails;
    hails.push_back(k);
    while (k != 1) {
        if (k % 2 == 0) {
            k /= 2;
        } else {
            k = k * 3 + 1;
        }
        hails.push_back(k);
    }
    
    int n = hails.size() - 1;
    
    for (int i = 0; i < ranges.size(); i++) {
        int x1 = ranges[i][0];
        int x2 = n + ranges[i][1];
        if (x1 > x2) {
            answer.push_back(-1);
        } else if (x1 == x2) {
            answer.push_back(0);
        } else {
            answer.push_back(getDefiniteIntegral(x1, x2, hails));
        }
    }
    return answer;
}