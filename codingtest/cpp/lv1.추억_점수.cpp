#include <string>
#include <vector>
#include<map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int>m;

    for (int i = 0; i < name.size(); i++) {
        m.insert(make_pair(name[i], yearning[i]));
    }
    int temp = 0;
    int answers = 0;
    string temps;
    for (int i = 0; i < photo.size(); i++) {
        
        answers = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            auto it = m.find(photo[i][j]);
            temp = distance(m.begin(), it);//�̰�  map������ �ε���
            if (it != m.end()) { // �����ϴ� ��쿡�� ���ϱ�
                answers += it->second;
            }




           
        }
        answer.push_back(answers);
    }
    return answer;
}