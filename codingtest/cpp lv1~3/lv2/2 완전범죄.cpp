#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;

    vector<pair<float, int>> B;
    for (int i = 0; i < info.size(); i++) {
        float a = info[i][0];
        float b = info[i][1];
        float c = b / a;
        B.push_back(make_pair(c, i)); // 효율과 인덱스를 저장
    }

    // 효율을 기준으로 내림차순 정렬 (효율이 높은 순으로 선택하려면 내림차순이 유리)
    sort(B.begin(), B.end(), greater<>());

    int countb = 0;
    vector<int> ind;

    for (int i = 0; i < B.size(); i++) {
        int index = B[i].second;
        countb += info[index][1];

        if (countb > m) break;  // 제한을 넘으면 종료

        ind.push_back(index);
    }

    int counta = 0;
    for (int i = 0; i < ind.size(); i++) {
        int index = ind[i];
        counta += info[index][0];  // 선택한 아이템들의 a 값 합산
    }

    if (counta > n) {
        answer = -1;
    }
    else {
        answer = counta;
    }

    return answer;
}
