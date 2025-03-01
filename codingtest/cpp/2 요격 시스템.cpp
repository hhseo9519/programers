#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    map<float, int>M1;
    for (float i = 0; i < 100, 000, 000; i += 0.5) {
        M1[i] = 0; //0.5 단위로 업데이트 된 상태의 map
    }
    for (vector<int> target : targets) {
        int start = target[0];
        int end = target[1];
        for (float i = target[0]; i < target[1]; i += 0.5) {
            if (i = target[0]) {
                continue;
            }
            M1[i] += 1;
        }
    }//이렇게 하면 그 좌표로 요격했을 때 걸리는 미사일의 개수가 나옴

    return answer;
}//실행시간 초과 out!!!