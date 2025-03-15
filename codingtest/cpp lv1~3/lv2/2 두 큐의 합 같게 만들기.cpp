#include <string>
#include <vector>
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    deque<int> dq1;
    long long q1s = 0, q2s = 0;
    for (int k : queue1) {
        q1s += k;
        
        dq1.push_back(k);
    }
    deque<int> dq2;
    for (int k : queue2) {
        q2s += k;
        
        dq2.push_back(k);
    }
    int count = 0;
    long front1, front2;
    int size = queue1.size() + queue2.size();
    //구할 수 없는 경우
    while (count <= size*2 ) { // 루프 종료 조건 강화
        if (q1s == q2s) {
            return count;
        }
        if (q1s > q2s) {
            int front1 = dq1.front();
            dq1.pop_front();
            dq2.push_back(front1);
            q1s -= front1;  //
            q2s += front1;  //
        }
        else {
            int front2 = dq2.front();
            dq2.pop_front();
            dq1.push_back(front2);
            q2s -= front2;  // 
            q1s += front2;  // 
        }
        count++;
    }
    
    return -1;
}