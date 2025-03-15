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
        B.push_back(make_pair(c, i)); // ȿ���� �ε����� ����
    }

    // ȿ���� �������� �������� ���� (ȿ���� ���� ������ �����Ϸ��� ���������� ����)
    sort(B.begin(), B.end(), greater<>());

    int countb = 0;
    vector<int> ind;

    for (int i = 0; i < B.size(); i++) {
        int index = B[i].second;
        countb += info[index][1];

        if (countb > m) break;  // ������ ������ ����

        ind.push_back(index);
    }

    int counta = 0;
    for (int i = 0; i < ind.size(); i++) {
        int index = ind[i];
        counta += info[index][0];  // ������ �����۵��� a �� �ջ�
    }

    if (counta > n) {
        answer = -1;
    }
    else {
        answer = counta;
    }

    return answer;
}
