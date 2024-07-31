#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
using namespace std;

int toMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int timeUnit = fees[2];
    int feeUnit = fees[3];
    map<string, vector<string>> m;
    for (string record: records) {
        stringstream ss;
        ss.str(record);
        string time, carNum, type;
        ss >> time >> carNum >> type;
        m[carNum].push_back(time);
    }
    for (auto& iter: m) {
        vector<string>& times = iter.second;
        if (times.size() % 2 == 1) {
            times.push_back("23:59");
        }
        int sum = 0;
        for (int i = 0; i < times.size(); i += 2) {
            sum += toMinutes(times[i + 1]) - toMinutes(times[i]);
        }
        int diff = sum - defaultTime;
        if (diff > 0) {
            answer.push_back(defaultFee + ceil(diff / (double)timeUnit) * feeUnit);
        } else {
            answer.push_back(defaultFee);
        }
    }
    return answer;
}