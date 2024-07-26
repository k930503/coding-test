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
    
    for (int i = 0; i < arrayB.size(); i++) {
        if (arrayB[i] % gcdVal == 0) {
            return 0;
        }
    }
    return gcdVal;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int a = findMaxDivisor(arrayA, arrayB);
    int b = findMaxDivisor(arrayB, arrayA);
    if (a < b) {
        a = b;
    }
    return a;
}