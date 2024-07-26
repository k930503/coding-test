#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    int temp;
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int findMaxDivisor(vector<int>& arrayA, vector<int>& arrayB) {
    int answer = 0;
    int gcdVal = arrayA[0];
    for (int i = 1; i < arrayA.size(); i++) {
        gcdVal = gcd(gcdVal, arrayA[i]);
    }
    vector<int> divisors;
    for (int i = 1; i <= gcdVal; i++) {
        if (gcdVal % i == 0) {
            divisors.push_back(i);
        }
    }
    
    for (int i = divisors.size() - 1; i >= 0; i--) {
        bool founded = true;
        for (int j = 0; j < arrayB.size(); j++) {
            if (arrayB[j] % divisors[i] == 0) {
                founded = false;
                break;
            }
        }
        if (founded) {
            return divisors[i];
        }
    }
    return answer;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int a = findMaxDivisor(arrayA, arrayB);
    int b = findMaxDivisor(arrayB, arrayA);
    if (a < b) {
        a = b;
    }
    return a;
}