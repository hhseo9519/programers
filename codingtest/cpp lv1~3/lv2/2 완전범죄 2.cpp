#include <string>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    //map���� �ڵ����� key��  value�� ���ϸ� ���� ���´�

    vector<pair<float, int>> B;
    for (int i = 0; i < info.size(); i++) {
        float a = info[i][0];
        float b = info[i][1];
        float c = a / b;
        B.push_back(make_pair(c, i));//ȿ��� i�� ���� ����


    }
    //B�� first�� �������� sorting
    sort(B.begin(), B.end());//�� �ĵ� ���ϰ� �ʹ� comp,,,���ٽ��� ���߿� ���� �ϴ� ������
    int countb = 0;
    vector <int> ind;//���⿡�� b�� ���� index���� ����.
    for (int i = 0; i < B.size(); i++) {

        int index = B[i].second;

        countb += info[index][1];
        if (countb >= m) {
            break;
        }
        ind.push_back(index);
    }
    int counta = 0;
    int k = 0;
    for (int i = 0; i < info.size(); i++) {
        int aa = info[i][0];
        for (int j = 0; j < ind.size(); j++) {
            if (ind[j] == i) {
                break;
            }
            else {
                counta += info[aa][0];
            }
        }
    }
    if (counta >= n) {
        answer = -1;
    }
    else {
        answer = counta;
    }
    return answer;
}