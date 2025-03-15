#include <string>
#include <vector>
#include<map>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    //map으로 자동정렬 key랑  value를 곱하면 쟤가 나온다

    vector<pair<float, int>> B;
    for (int i = 0; i < info.size(); i++) {
        float a = info[i][0];
        float b = info[i][1];
        float c = a / b;
        B.push_back(make_pair(c, i));//효울과 i를 집어 넣음


    }
    //B의 first를 기준으로 sorting
    sort(B.begin(), B.end());//이 식도 구하고 싶다 comp,,,람다식은 나중에 쓰고 일단 만들자
    int countb = 0;
    vector <int> ind;//여기에는 b가 먹은 index들이 들어간다.
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