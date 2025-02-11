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
        auto it2 = m2.find(fval);//map.find()는 pair를 가리키는 반복자를 반환한다.
        //포인터처럼 접근해서 두개의 정보를 바꾼다.
        auto previt2 = prev(it2);
        swap(it2->second, previt2->second);

        auto final=m1.find(it2->second);
        auto final2 = m1.find(previt2->second);
        swap(final->second, final2->second);

    }
    //map에 들어있는걸 answer로 옮겨
    for (auto k = m2.begin(); k != m2.end(); ++k) {
        answer.push_back(k->second);
    }


    return answer;
}

//map을 한번만 사용하는 풀이
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> m1;

    // 선수의 이름과 인덱스를 map에 저장
    for (int i = 0; i < players.size(); i++) {
        m1[players[i]] = i;  // 선수 이름을 키로, 순위를 값으로 저장
    }

    // 호출된 선수들에 대해 순위를 바꿈
    for (int i = 0; i < callings.size(); i++) {
        string calledPlayer = callings[i];
        int currentPos = m1[calledPlayer];  // 호출된 선수의 현재 순위
        if (currentPos > 0) {
            // 바로 앞선 선수와 위치를 교환
            string frontPlayer = players[currentPos - 1];  // 앞선 선수의 이름
            m1[frontPlayer] = currentPos;  // 앞선 선수의 순위 변경
            m1[calledPlayer] = currentPos - 1;  // 호출된 선수의 순위 변경

            // 선수의 이름과 순위 매칭
            swap(players[currentPos], players[currentPos - 1]);
        }
    }

    // 최종 순위를 answer에 담기
    return players;
}
