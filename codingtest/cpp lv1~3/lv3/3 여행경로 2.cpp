#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
#include<queue>;
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>>M;
    for (int i = 0; i < tickets.size(); i++) {
        string start = tickets[i][0];
        string end = tickets[i][1];
        M[start].push_back(end);
        sort(M[start].begin(), M[start].end());//오름차순 정렬인가
    }
    queue<string>q;
    int n = tickets.size();
    int count = 0;
    q.push("ICN");
    while (!q.empty()) {//dfs밖에 생각이 안나...
        auto start = q.front();
        answer.push_back(start);
        count++;
        
        if (count < n&&M[start].size()==0) {
            answer.pop_back();

        }
        q.pop();
        for (string k : M[start]) {
            q.push(k);
        }

        
    }
    //dfs로 하는게 맞았다.. bfs 문제는 다른 문제를 찾아보자


    return answer;
}