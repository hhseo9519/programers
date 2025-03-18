#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<string>>M;
    for (int i = 0; i < tickets.size(); i++) {
        string start = tickets[i][0];
        string end = tickets[i][1];
        M[start].push_back(end);
        sort(M[start].begin(), M[start].end());//�������� �����ΰ�
    }



    string start = "ICN";
    answer.push_back("ICN");
    for (int i = 0; i < tickets.size(); i++) {
        if (M[start].begin() != M[start].end()) {//�迭�ε� string�� ��Ÿ���°� �ƴѰ�?
            string arrive = M[start][0];
            M[start].erase(find(M[start].begin(), M[start].end(), arrive));
            start = arrive;
            answer.push_back(arrive);
        }
    }
    return answer;
}