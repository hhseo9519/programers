#include <string>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int>m1;
    map<int, string>m2;

    for (int i = 0; i < players.size(); i++) {
        m1.insert(make_pair(players[i], i));
        m2.insert(pair<int, string>(i, players[i]));
    }
    int fval = 0;
    string sval;
    for (int i = 0; i < callings.size(); i++) {
        auto it = m1.find(callings[i]);
        fval = it->second;
        auto it2 = m2.find(fval);//map.find()�� pair�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
        //������ó�� �����ؼ� �ΰ��� ������ �ٲ۴�.
        auto previt2 = prev(it2);
        swap(it2->second, previt2->second);

        auto final=m1.find(it2->second);
        auto final2 = m1.find(previt2->second);
        swap(final->second, final2->second);

    }
    //map�� ����ִ°� answer�� �Ű�
    for (auto k = m2.begin(); k != m2.end(); ++k) {
        answer.push_back(k->second);
    }


    return answer;
}

//map�� �ѹ��� ����ϴ� Ǯ��
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m1;

    // ������ �̸��� �ε����� map�� ����
    for (int i = 0; i < players.size(); i++) {
        m1[players[i]] = i;  // ���� �̸��� Ű��, ������ ������ ����
    }

    // ȣ��� �����鿡 ���� ������ �ٲ�
    for (int i = 0; i < callings.size(); i++) {
        string calledPlayer = callings[i];
        int currentPos = m1[calledPlayer];  // ȣ��� ������ ���� ����
        if (currentPos > 0) {
            // �ٷ� �ռ� ������ ��ġ�� ��ȯ
            string frontPlayer = players[currentPos - 1];  // �ռ� ������ �̸�
            m1[frontPlayer] = currentPos;  // �ռ� ������ ���� ����
            m1[calledPlayer] = currentPos - 1;  // ȣ��� ������ ���� ����

            // ������ �̸��� ���� ��Ī
            swap(players[currentPos], players[currentPos - 1]);
        }
    }

    // ���� ������ answer�� ���
    return players;
}
