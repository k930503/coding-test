#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool isPrime(long long n) {
    if (n == 1) {
        return false;
    }
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

string changeFormation(int n, int k) {
    string ret;
    while (n != 0) {
        int temp = n % k;
        ret = to_string(temp) + ret;
        n /= k;
    }
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    
    string str = changeFormation(n, k);
    stringstream ss;
    ss.str(str);
    string token;
    vector<long long> v;
    while (getline(ss, token, '0')) {
        if (!token.empty()) {
            v.push_back(stoll(token));
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (isPrime(v[i])) {
            answer++;
        }
    }
    return answer;
}