#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    unordered_set<int> us;
    for (int i = 1; i <= elements.size(); i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += elements[j];
        }
        us.insert(sum);
        for (int j = 1; j < elements.size(); j++) {
            sum -= elements[j - 1];
            sum += elements[(j + i - 1) % elements.size()];
            us.insert(sum);
        }
    }
    answer = us.size();
    return answer;
}