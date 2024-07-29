#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    vector<int> v = queue1;
    v.insert(v.end(), queue2.begin(), queue2.end());
    int start = 0;
    int end = queue1.size() - 1;
    long long sumQueue1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    if (sum % 2 == 1) {
        return answer;
    }
    long long target = sum / 2;
    while (start <= end || end < v.size()) {
        if (sumQueue1 == target) {
            return start + (end - (queue1.size() - 1));
        }
        
        if (sumQueue1 < target) {
            end++;
            if (end < v.size()) {
                sumQueue1 += v[end];
            }
        } else {
            sumQueue1 -= v[start];
            start++;
        }
    }
    return answer;
}