#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for (int i = 0; i <= d; i += k) {
        long long scope = sqrt((long long)d * d - (long long)i * i);
        answer += scope / k + 1;
    }
    return answer;
}