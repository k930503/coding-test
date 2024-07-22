#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> book;
vector<book> my_book_time;

struct cmp {
    bool operator()(book a, book b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    my_book_time.resize(book_time.size());
    for (int i = 0; i < book_time.size(); i++) {
        book time;
        for (int j = 0; j < book_time[i].size(); j++) {
            int hour = stoi(book_time[i][j].substr(0, 2));
            int minute = stoi(book_time[i][j].substr(3, 2));
            int temp = hour * 60 + minute;
            if (j == 0) {
                time.first = temp;
            } else {
                time.second = temp + 10;
            }
        }
        my_book_time[i] = time;
    }
    
    sort(my_book_time.begin(), my_book_time.end());
    
    priority_queue<book, vector<book>, cmp> pq;
    pq.push(my_book_time[0]);
    for (int i = 1; i < my_book_time.size(); i++) {
        int curEndTime = pq.top().second;
        int curStartTime = my_book_time[i].first;
        if (curEndTime <= curStartTime) {
            pq.pop();
            pq.push(my_book_time[i]);
        } else {
            pq.push(my_book_time[i]);
        }
    }
    
    answer = pq.size();
    return answer;
}