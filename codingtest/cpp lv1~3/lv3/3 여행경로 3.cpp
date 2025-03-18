#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<string>ans;


void dfs(int count, int n,string nx, vector<string>& answer, unordered_map<string, vector<string>>M) {
    if (count == n+1) {
        answer = ans;
    }
    ans.push_back(nx);
    for (string k : M[nx]) {
        dfs(count + 1, n, k, answer, M);
    }
    ans.pop_back();
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>>M;
    for (int i = 0; i < tickets.size(); i++) {
        string start = tickets[i][0];
        string end = tickets[i][1];
        M[start].push_back(end);
        sort(M[start].begin(), M[start].end());//오름차순 정렬인가
    }
   
    int n = tickets.size();
    dfs(0, n, "ICN", answer, M);


   
    return answer;
}